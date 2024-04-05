#include "main.h"

/**
 * shell_cd - changes the current directory
 * args: the array of arguments
*/

void shell_cd(char **args)
{
    char *dir = args[1];
     char *oldpwd;

    if (dir == NULL)
    {
        dir = _getenv("HOME");
        if (dir == NULL)
        {
            printf("NO Found HOME dir\n");
            return;
        }
    }
    oldpwd = getenv("PWD");
    if (oldpwd == NULL) {
        printf("PWD environment variable not set\n");
        return;
    }
    if (chdir(dir) == -1)
    {
        perror("cd");
        return;
    }
     if (setenv("PWD", dir, 1) == -1) {
        perror("setenv");
        setenv("PWD", oldpwd, 1);
    }
}
