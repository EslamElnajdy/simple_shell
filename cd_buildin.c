#include "main.h"

/**
 * shell_cd - changes the current directory
 * args: the array of arguments
*/

void shell_cd(char **args)
{
    char *dir = args[1];
    if (dir == NULL)
    {
        dir = _getenv("HOME");
        if (dir == NULL)
        {
            printf("NO Found HOME dir\n");
            return;
        }
    }
    if (chdir(args[1]) == -1)
    {
        perror("cd");
    }
}