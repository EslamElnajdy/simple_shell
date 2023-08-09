#include "main.h"

/**
 * exit_builtin - exit to end
 * @args: command array
 *
 * Return: 0 if failure 1 if sucess
 */
int exit_builtin(char **args)
{
	if (args[1] != NULL)
		exit(atoi(args[1]));
	else
		return (EXIT_CODE);
}