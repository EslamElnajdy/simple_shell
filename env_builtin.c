#include "main.h"
#include <unistd.h>

/**
 * shell_env - Prints the environment variables.
 *
 * Return: void.
 */
int shell_env(void)
{
	int i;

	for (i = 0; __environ[i]; i++)
	{
		puts(__environ[i]);
		putchar('\n');
	}

	return (i);
}