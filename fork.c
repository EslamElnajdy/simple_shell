#include "main.h"

/**
 * _fork - fork child process.
 *
 * @tokens: argument_1
 * @cmd: string cmd
 *
 * Return: void
 */
int _fork(char *cmd, char **tokens)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: fork child");
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(cmd, tokens, __environ) == -1)
		{
			perror("execve: ");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		free(cmd);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (!isatty(STDIN_FILENO))
			return (status);
	}
	return (0);
}
