#include "main.h"

/**
 * is_builtin - checks if the command is a builtin
 * @args: the array
 * Return: 1 if command, 0 otherwise
 */
int is_builtin(char **args)
{
	if (!args[0])
		return (0);
	if (!strcmp(args[0], "exit"))
		exit_builtin(args);
	else if (!strcmp(args[0], "env"))
		shell_env();
	else
		return (0);
	return (1);
}
