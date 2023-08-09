#include "main.h"

/**
 * is_valid_path - for check is valid
 *
 * @filename: string
 *
 * Return: 1 is executable or 0 if not
 */
int is_valid_path(char *filename)
{
	size_t length = strlen(filename);

	if (length >= strlen("../"))
		if (strncmp(filename, "../", strlen("../")) == 0)
			return (1);
	if (length >= strlen("./"))
		if (strncmp(filename, "./", strlen("./")) == 0)
			return (1);
	if (length >= strlen("/"))
		if (strncmp(filename, "/", strlen("/")) == 0)
			return (1);
	return (0);
}

/**
 * filepath_creator - file creator
 *
 * @file_path: argument_1 description
 * @tokens: argument_2 description
 * @filename: file name string
 * @i: index to copy
 *
 * Return: void
 */
void filepath_creator(char **file_path, char **tokens,
		char *filename, int i)
{
	malloc_char(file_path, (strlen(tokens[i]) + strlen(filename) + 2)
				, "malloc failed for file_path");
	strcpy(*file_path, tokens[i]);
	strcat(*file_path, "/");
	strcat(*file_path, filename);
	strcat(*file_path, "\0");
}

/**
 * _getpath - get the path
 *
 * @filename: argument 1
 *
 * Return: path
 */
char *_getpath(char *filename)
{
	struct stat sb;
	char *path, *delim, *file_path;
	char **tokens;
	int i, file_exist;

	delim = ":";
	path = _getenv("PATH");
	if (path != NULL)
	{
		tokens = tokenize(path, delim);
		if (tokens != NULL)
		{
			for (i = 0; tokens[i]; i++)
			{
				filepath_creator(&file_path, tokens, filename, i);
				file_exist = stat(file_path, &sb);
				if (file_exist == 0)
				{
					free_get(&path, tokens);
					return (file_path);
				}
				free(file_path);
			}
			free_get(&path, tokens);
		}
		else
			free(path);
	}
	file_exist = stat(filename, &sb);
	if (file_exist == 0 && is_valid_path(filename))
		return (strdup(filename));
	return (NULL);
}
