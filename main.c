#include "main.h"

/**
 * main - short description
 *
 * Description: long description
 *
 * @ac: argument_1 description
 * @args: argument_2 description
 * @envp: argument_3 desctiontion
 *
 * Return: return description
 */
int main(int ac, char **args, char **envp)
{
	int status = 0;
	char *input, *path;
	size_t number_malloc, cmd_num;
	char **tokens;

	(void)ac;
	(void)envp;
	input = NULL;
	number_malloc = cmd_num = 0;
	while (1)
	{
		cmd_num++;
		_getline(&input, &number_malloc, status);
		tokens = tokenize_input(input);
		if (!(*tokens))
			status = 0;
		else
		{
			if (is_builtin(tokens))
			{
				free_main(tokens, input);
				exit(status);
			}
			else
			{
				path = _getpath(tokens[0]);
				if (path !=  NULL)
					status = _fork(path, tokens);
				else
					status = error_not_found(args, tokens, cmd_num);
			}
		}
		free_main(tokens, input);
		input = NULL;
	}
	return (0);
}
