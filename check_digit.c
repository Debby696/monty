#include "monty.h"

/**
 * check_digit - function that checks if all character in a string are digits.
 * @str: string inputt.
 * Return: 0 if all are digits else -1.
 */
int check_digit(char *str)
{
	int x = 0;

	if (str == NULL)
		return (-1);

	while (str[x] != '\0')
	{
		if (str[x] >= '0' && str[x] <= '9')
		{
			x++;
			continue;
		}
		return (-1);
	}
	return (0);
}
