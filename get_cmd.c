#include "monty.h"

/**
 * get_cmd - function that gets commands from the object file.
 * @line_number: line position of command
 * Return: pointer to the returned command.
 */
char *get_cmd(unsigned int line_number)
{
	size_t x = 0;
	char cpy[4096] = {'\0'}, *ptr = &cpy[0];

	strcpy(&cpy[0], &open_file[0]);

	if (line_number == 1)
		return (_strtok(ptr, "\n"));

	ptr = strtok(&cpy[0], "\n");
	x++;
	while (x < line_number)
	{
		ptr = strtok(NULL, "\n");
		x++;
	}

	return (ptr);
}
