#include "../include/lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LALEN_VERSION "0.1.0"

void print_help(const char *prog) {
    printf("Usage: %s <git-subcommand> [options]\n", prog);
    printf("\nExamples:\n");
    printf("  %s init\n", prog);
    printf("  %s add ~/.config/kitty\n", prog);
    printf("  %s commit -m \"Add kitty config\"\n", prog);
    printf("  %s push -u origin master\n", prog);
    printf("\nOptions:\n");
    printf("  --help      Show this help message\n");
    printf("  --version   Show version info\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help(argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0) {
        print_help(argv[0]);
        return 0;
    }

    if (strcmp(argv[1], "--version") == 0) {
        printf("lalen version %s\n", LALEN_VERSION);
        return 0;
    }

    char *home = getenv("HOME");
    if (home == NULL) {
        fprintf(stderr, "HOME environment variable not set\n");
        return 1;
    }

    return check_git() ? lalen_cmd(home, argv + 1) : 1;
}
