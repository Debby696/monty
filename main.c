#include "monty.h"

/**
 * _strlen - function that returns the length of a string
 * @str: string input
 * Return: length of string
 */
int _strlen(char *str)
{
	int x = 0;

	if (str == NULL)
		return (0);

	while (str[x] != '\0')
		x++;

	return (x);
}
/**
* create_node - function that creates a new stack node.
* @n: Data that the node will carry.
* Return: Address of the new node.
*/
stack_t *create_node(int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	node->n = n;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
/**
* handle_error - function that prints error messages.
* @option: integer indicating which error occurred.
* @argv: list of cmd line arguments.
* @ln_number: line number that error occurred on
* Return: void
*/
void handle_error(int option, char **argv, int ln_number)
{
	char err[4096] = {'\0'};

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
			_strcpy(&err[_strlen(err)], itoa(ln_number + 1));
			_strcpy(&err[_strlen(err)], ": usage: push integer\n");
			break;
		default:
			return;
	}

	write(STDERR_FILENO, err, _strlen(err));
	exit(EXIT_FAILURE);
}
/**
* run_commands - function that runs monty commands.
* @av: list of commands from the object file.
* @head: first node of stack_t doubly linked list.
* @argv: list of command line arguments.
* Return: void
*/
void run_commands(char **av, stack_t *head, char **argv)
{
	int x = 0;
	char *cur = NULL, *second_arg = NULL;

	while (av[x] != NULL)
	{
		cur = _strtok(av[x], " ");
		if (_strcmp(cur, "push") == 0)
		{
			second_arg = _strtok(NULL, " ");
			if (check_digit(second_arg) == 0)
				push(&head, atoi(second_arg));
			else
				handle_error(3, argv, x);
		}
		else if (_strcmp(cur, "pall") == 0)
			pall(head);
		x++;
	}
}
/**
 * main - entry point
 * @ac: Argument count.
 * @argv: list of command line arguments.
 * Return: int
*/
int main(int ac, char **argv)
{
	stack_t *head = NULL;
	int handle_open, x = 0;
	char output_buff[4096] = {'\0'}, *cmds[4096];

	if (ac <= 1)
		handle_error(1, argv, 0);

	handle_open = open(argv[1], O_RDONLY);
	if (handle_open == -1)
		handle_error(2, argv, 0);

	read(handle_open, output_buff, 4096);

	cmds[x] = _strtok(output_buff, "\n");
	while (cmds[x] != NULL)
	{
		x++;
		cmds[x] = _strtok(NULL, "\n");
	}
	run_commands(cmds, head, argv);
	return (0);
}
