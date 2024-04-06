#include "main.h"

/**
 * shell_cd - changes the current directory
 * args: the array of arguments
*/

void shell_cd(char **args)
{
    char *dir;
    char buffer[1024];

    char *cwd = getcwd(buffer, sizeof(buffer));
    if (cwd == NULL) {
        perror("getcwd");
        return;
    }

    if (args[1] == NULL) {

        dir = getenv("HOME");
        if (dir == NULL)
            dir = getenv("PWD");
    } else if (strcmp(args[1], "-") == 0) {

        dir = getenv("OLDPWD");
        if (dir == NULL) {
            printf("%s\n", cwd);
            return;
        }
    } else {
        dir = args[1];
    }

    if (setenv("OLDPWD", cwd, 1) == -1) {
    perror("setenv");
    return;
    }
    if (chdir(dir) == -1) {
        perror("cd");
        return;
    }

    cwd = getcwd(buffer, sizeof(buffer));
    if (cwd == NULL) {
        perror("getcwd");
        return;
    }

    if (setenv("PWD", cwd, 1) == -1) {
        perror("setenv");
        return;
    }
}