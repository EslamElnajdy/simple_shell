#include "main.h"

/**
 * error_not_found - Printing error
 * @args: command
 * @tokens: tokenized
 * @cmd_num: counter
 *
 * Return: void
 */
int error_not_found(char **args, char **tokens, size_t cmd_num)
{
	char *err_str;
	char *cmd_num_str = _itoa(cmd_num);
	int size = (strlen(args[0]) + (2 * strlen(": ")) + digit(cmd_num)
				 + strlen(tokens[0]) + strlen(": not found\n") + 1);

	malloc_char(&err_str, size, "Error: malloc error");
	strcpy(err_str, args[0]);
	strcat(err_str, ": ");
	strcat(err_str, cmd_num_str);
	strcat(err_str, ": ");
	strcat(err_str, tokens[0]);
	strcat(err_str, ": not found\n");
	strcat(err_str, "\0");

	write(STDERR_FILENO, err_str, strlen(err_str));
	free(err_str);
	free(cmd_num_str);
	return (127);
}
