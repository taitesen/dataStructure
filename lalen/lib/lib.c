#include "../include/lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int check_git(void) {
    if (system("command -v git > /dev/null 2>&1") != 0) {
        fprintf(stderr, "git command not found in $PATH\n");
        return 0; // not found
    }
    if (system("git --version | awk '{print $3}' | awk -F. '{if($1>1 || ($1==1 " "&& $2>=7)) exit 0; else exit 1}' > /dev/null 2>&1") != 0) {
        fprintf(stderr, "Warning: git 1.7.0+ recommended for best compatibility\n");
        // Don't fail, just warn
    }
    return 1; // found
}

int lalen_check_repo(char *home) {
    char lalen_path[SHORT], lalen_path_head[SHORT];
    struct stat st;

    snprintf(lalen_path, sizeof(lalen_path), "%s/.lalen", home);
    snprintf(lalen_path_head, sizeof(lalen_path_head), "%s/.lalen/HEAD", home);

    // Check if .lalen directory exists
    if (stat(lalen_path, &st) != 0) {
        return 0; // .lalen dir does not exists
    }

    // Check if its a directory
    if (!S_ISDIR(st.st_mode)) {
        return -1; // .lalen exits but its not a dir
    }

    // Check if its a git repository (has HEAD file)
    if (stat(lalen_path_head, &st) == 0) {
        return 1; // Valid git repository
    }

    return 2; // Dir exists but not a git repository
}

int init_handler(char *home, char *argv[]) {
    int repo_status = lalen_check_repo(home);

    switch (repo_status) {
    case 1:
        printf("lalen repository already exists at" GREEN "%s/.lalen\n" RESET, home);
        printf("USAGE:" GREEN "'lalen" MAUVE "status'" MAUVE "to see the current state\n");
        return 0; // Success but no action required

    case -1:
        fprintf(stderr, RED "Error:" GREEN "%s/.lalen" RESET "exits but its not a directory\n", home);
        fprintf(stderr, "Remove or rename the file before initializing\n");
        return 1;

    case 2:
        fprintf(stderr,
                YELLOW "WARNING:" GREEN "%s/.lalen" RESET "exists but it is not a git repository\n", home);
        printf( "Do you want to remove it, and create a new repository? (y/N): ");
        fflush(stdout);

        char response[10];
        if (fgets(response, sizeof(response), stdin) != NULL &&
            (response[0] == 'y' || response[0] == 'Y')) {
            char rm_command[SHORT + 16];
            snprintf(rm_command, sizeof(rm_command), "rm -rf %s/.lalen", home);
            if (system(rm_command) != 0) {
                fprintf(stderr, "Failed to removed existing" GREEN ".lalen" RESET "directory\n");
                return 1;
            }
            printf("Removed existing" GREEN ".lalen" RESET "directory\n");
        } else {
            printf("Initialization cancelled...\n");
            return 1;
        }
        break;

    case 0:
        // Directory doesnot exist proceed with normal init
        break;
    }

    return lalen_cmd_internal(home, argv);
}

int lalen_cmd_internal(char *home, char *argv[]) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    // count how many argv are passed
    int argc = 0;
    while (argv[argc] != NULL)
        argc++;

    char git_dir[SHORT], work_tree[SHORT];
    snprintf(git_dir, sizeof(git_dir), "--git-dir=%s/.lalen", home);
    snprintf(work_tree, sizeof(work_tree), "--work-tree=%s", home);

    if (pid == 0) {

        // Allocate for execvp: git, git_dir, work_tree, argv[], NULL
        int max_args = argc + 4;
        char *args[max_args];

        args[0] = "git";
        args[1] = git_dir;
        args[2] = work_tree;

        for (int i = 0; i < argc; ++i) {
            args[i + 3] = argv[i];
        }
        args[argc + 3] = NULL;

        execvp("git", args);
        perror("execvp");
        exit(1);
    }

    int status;
    waitpid(pid, &status, 0);
    int exit_status = WIFEXITED(status) ? WEXITSTATUS(status) : 1;

    if (exit_status == 0 && argc > 0 && strcmp(argv[0], "init") == 0) {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            char *config_args[] = {"git",     git_dir,
                                   work_tree, "config",
                                   "--local", "status.showUntrackedFiles",
                                   "no",      NULL};
            execvp("git", config_args);
            perror("execvp config_args");
            exit(1);
        }
        waitpid(pid2, &status, 0);
        return WIFEXITED(status) ? WEXITSTATUS(status) : 1;
    }

    return exit_status;
}

int lalen_cmd(char *home, char **argv) {
    if (argv[0] != NULL && strcmp(argv[0], "init") == 0) {
        return init_handler(home, argv);
    }

    int repo_status = lalen_check_repo(home);
    if (repo_status != 1) {
        fprintf(stderr, RED "ERROR:" RESET "No lalen repository found in %s", home);
        fprintf(stderr, "Run" GREEN "'lalen" MAUVE "init'" RESET "first to initialize a repository\n");
        return 1;
    }
    return lalen_cmd_internal(home, argv);
}
