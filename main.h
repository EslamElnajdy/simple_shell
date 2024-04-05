#ifndef MAIN_H
#define MAIN_H
#define EXIT_CODE 1080

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>


void prompt(void);
ssize_t _getline(char **input, size_t *number_malloc, int status);
int _fork(char *command, char **array_of_tokens);
char *_getpath(char *filename);
char *_getenv(const char *name);
char *malloc_char(char **string, size_t size_of_malloc, char *error_message);
char **malloc_array(char **array, size_t size_of_malloc, char *error_message);
void free_get(char **path_var, char **array_of_tokens);
void free_main(char **array_of_tokens, char *input);
char *_itoa(size_t command_num);
void reverse_string(char *str);
int digit(size_t cmd_num);
int error_not_found(char **arvs, char **array_of_tokens, size_t command_num);
char **tokenize(char *str, const char *delim);
char **tokenize_input(char *input);

int exit_builtin(char **args);
int is_builtin(char **args);
int shell_env(void);
int shell_setenv(char **args);
int shell_unsetenv(char **args);
void shell_cd(char **args);
#endif
