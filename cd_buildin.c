#include "main.h"

/**
 * shell_cd - changes the current directory
 * args: the array of arguments
*/

void shell_cd(char **args)
{
    char *dir = args[1];
    char *oldpwd;

    oldpwd = getenv("PWD");
    if (oldpwd == NULL)
    {
        printf("PWD environment variable not set\n");
        return;
    }
    if (dir == NULL)
    {
        dir = getenv("HOME");
        if (dir == NULL)
        {
            printf("HOME environment variable not set\n");
            return;
        }
    }
    else if (strcmp(dir, "-") == 0)
    {
        dir = getenv("OLDPWD");
        if (dir == NULL)
        {
            printf("OLDPWD environment variable not set\n");
            return;
        }
    }

    if (chdir(dir) == -1)
    {
        perror("cd");
        return;
    }

    if (setenv("OLDPWD", oldpwd, 1) == -1)
    {
        perror("setenv");
        return;
    }

    if (setenv("PWD", dir, 1) == -1)
    {
        perror("setenv");
        return;
    }
}
