#include "monty.h"
/**
 * itoa - function that converts an integer to a string.
 * @val: int that's to be converted
 * Return: Pointer to the new string
 */
char *itoa(int val)
{
	char src[4096] = {'0'}, *str = &src[0];
	int temp;

	if (val == 0)
	{
		*str = '0';
		return (str);
	}
	if (val < 0)
	{
		val *= -1;
		*str++ = -1;
	}
	for (temp = val; temp > 0; temp /= 10)
	{
		*str = '\0';
		str++;
	}
	for (temp = val; temp > 0; temp /= 10)
		*--str = temp % 10 + '0';
	return (str);
}
