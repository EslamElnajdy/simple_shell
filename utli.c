#include "main.h"

/**
 * malloc_char - memory allocation
 *
 * @string: to string
 * @size_of_malloc: size of malloc
 * @error_message: error message
 *
 * Return: the memory
 */
char *malloc_char(char **string, size_t size_of_malloc, char *error_message)
{
	*string = (char *) malloc(sizeof(char) * size_of_malloc);
	if (string == NULL)
	{
		perror(error_message);
		return (NULL);
	}
	return (*string);
}

/**
 * malloc_array - array memory
 *
 * @array: string
 * @size_of_malloc: size of malloc
 * @error_message: error message
 *
 * Return: memory
 */
char **malloc_array(char **array, size_t size_of_malloc, char *error_message)
{
	array = (char **) malloc(sizeof(char *) * size_of_malloc);
	if (array == NULL)
	{
		perror(error_message);
		return (NULL);
	}
	return (array);
}
