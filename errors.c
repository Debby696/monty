#include "monty.h"

/**
* handle_error - function that prints error messages.
* @option: integer indicating which error occurred.
* @argv: list of cmd line arguments.
* @ln_number: line number that error occurred on
* @opcode: operation code that caused the error
* Return: void
*/
void handle_error(int option, char **argv, int ln_number, char *opcode)
{
	char err[4096] = {'\0'}, num[4096] = {'\0'};

	switch (option)
	{
		case 1:
			_strcpy(&err[0], "USAGE: monty file\n");
			break;
		case 2:
			_strcpy(&err[0], "Error: can't open file ");
			_strcpy(&err[_strlen(err)], argv[1]);
			_strcpy(&err[_strlen(err)], "\n");
			break;
		case 3:
			_strcpy(&err[0], "L");
			_strcpy(&err[_strlen(err)], itoa(ln_number + 1, &num[0]));
			_strcpy(&err[_strlen(err)], ": usage: push integer\n");
			break;
		case 4:
			_strcpy(&err[0], "L");
			_strcpy(&err[_strlen(err)], itoa(ln_number + 1, &num[0]));
			_strcpy(&err[_strlen(err)], ": unknown intruction ");
			_strcpy(&err[_strlen(err)], opcode);
			_strcpy(&err[_strlen(err)], "\n");
			break;
		default:
			return;
	}

	write(STDERR_FILENO, err, _strlen(err));
	exit(EXIT_FAILURE);
}
