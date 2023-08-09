#include "main.h"

/**
 * free_main - free array of tokens
 * @array_tokens: tokenized string
 * @input: string
 *
 * Return: void
 */
void free_main(char **array_tokens, char *input)
{
	int index;

	for (index = 0; array_tokens[index]; index++)
		free(array_tokens[index]);
	free(array_tokens);
	free(input);
}

/**
 * free_get - free the file
 *
 * @path_var: argument_1 description
 * @tokens: argument_2 description
 *
 * Return: return description
 */
void free_get(char **path_var, char **tokens)
{
	int index;

	if (tokens != NULL)
	{
		for (index = 0; tokens[index]; index++)
			if (tokens[index] != NULL)
				free(tokens[index]);
		free(tokens);
	}
	if (*path_var != NULL)
		free(*path_var);
}
