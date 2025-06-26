#ifndef LALEN_H
#define LALEN_H

// Buffer size constant
#define SHORT 1024
#define LONG 2048

#define YELLOW "\033[33m"
#define GREEN  "\033[32m"
#define RED    "\033[31m"
#define RESET  "\033[0m"
#define MAUVE "\033[35m"


#ifdef __cplusplus
extern "C" {
#endif

// Function declaration
int check_git(void);
int lalen_check_repo(char *home);
int init_handler(char *home, char *argv[]);
int lalen_cmd_internal(char *home, char *argv[]);
int lalen_cmd(char *home, char *argv[]);

#ifdef __cplusplus
}
#endif

#endif // LALEN_H
