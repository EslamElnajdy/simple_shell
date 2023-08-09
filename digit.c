#include "main.h"

/**
 * digit - counts the digit
 * @cmd_num: the number
 *
 * Return: the number
 */
int digit(size_t cmd_num)
{
	int digit = 0;

	if (cmd_num == 0)
		return (1);
	while (cmd_num != 0)
	{
		cmd_num /= 10;
		digit++;
	}

	return (digit);
}
