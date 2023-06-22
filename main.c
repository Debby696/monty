#include "monty.h"

/**
 * _strlen - function that returns the length of a string
 * @str: string input
 * Return: length of string
 */
int _strlen(char *str)
{
	int x = 0;

	while (*str)
	{
		x++;
		str++;
	}

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
 * free_stack - function that frees memory in a linked list.
 * @head: first node of linked list.
 * Return: void
 */
void free_stack(stack_t *head)
{
	if (head != NULL)
		free_stack(head->next);
	free(head);
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
		if (cur == NULL)
		{
			x++;
			continue;
		}
		if (_strcmp(cur, "push") == 0)
		{
			second_arg = _strtok(NULL, " ");
			if (second_arg == NULL)
				handle_error(3, argv, x, NULL);
			if (check_digit(second_arg) == 0)
				push(&head, atoi(second_arg));
			else if (atoi(second_arg) != 0)
				push(&head, atoi(second_arg));
			else
			{
				free_stack(head);
				handle_error(3, argv, x, NULL);
			}
		}
		else if (_strcmp(cur, "pall") == 0)
			pall(head);
		else if (_strcmp(cur, "pint") == 0)
			pint(head, x);
		else
		{
			free_stack(head);
			handle_error(4, argv, x, cur);
		}
		x++;
	}
	free_stack(head);
	exit(EXIT_SUCCESS);
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

	if (ac != 2)
		handle_error(1, argv, 0, NULL);

	handle_open = open(argv[1], O_RDONLY);
	if (handle_open == -1)
		handle_error(2, argv, 0, NULL);

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
