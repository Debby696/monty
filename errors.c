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
			strcat(&err[0], "USAGE: monty file\n");
			break;
		case 2:
			strcat(&err[0], "Error: can't open file ");
			strcat(&err[strlen(err)], argv[1]);
			strcat(&err[strlen(err)], "\n");
			break;
		case 3:
			strcat(&err[0], "L");
			strcat(&err[strlen(err)], itoa(ln_number, &num[0]));
			strcat(&err[strlen(err)], ": usage: push integer\n");
			break;
		case 4:
			strcat(&err[0], "L");
			strcat(&err[strlen(err)], itoa(ln_number, &num[0]));
			strcat(&err[strlen(err)], ": unknown intruction ");
			strcat(&err[strlen(err)], opcode);
			strcat(&err[strlen(err)], "\n");
			break;
		case 5:
			strcat(&err[0], "L");
			strcat(&err[strlen(err)], itoa(ln_number, &num[0]));
			strcat(&err[strlen(err)], ": can't pint, stack empty\n");
			break;
		default:
			return;
	}

	write(STDERR_FILENO, err, strlen(err));
	exit(EXIT_FAILURE);
}
