#include "main.h"

/**
 * _getline - get the input
 * @input: description
 * @number_malloc: description
 * @status: the exit status
 *
 * Return: -1 on failure greater than 0 on success
 */
ssize_t _getline(char **input, size_t *number_malloc, int status)
{

	prompt();
	if (getline(input, number_malloc, stdin) == -1)
	{
		free(*input);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}
	return (0);
}
