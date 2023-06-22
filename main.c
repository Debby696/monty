#include "monty.h"

char open_file[4096] = {'\0'};

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
 * run_opcodes - function that runs the opcodes.
 * @cmds: list of lines of command from the bytecode file
 * Return: void
 */
void run_opcodes(char **cmds)
{
	stack_t *head = NULL;
	char *tmp = NULL;
	int x = 0, i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	x = 0;
	while (cmds[x] != NULL)
	{
		tmp = strtok(cmds[x], " ");
		if (tmp == NULL)
		{
			x++;
			continue;
		}
		while (ops[i].opcode != NULL)
		{
			if (strcmp(tmp, ops[i].opcode) == 0)
			{
				ops[i].f(&head, x + 1);
				break;
			}
			i++;
		}
		x++;
		i = 0;
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
	int handle_open = 0, x = 0;
	char output_buff[4096] = {'\0'}, *cmds[4096];

	if (ac != 2)
		handle_error(1, argv, 0, NULL);

	handle_open = open(argv[1], O_RDONLY);

	if (handle_open == -1)
		handle_error(2, argv, 0, NULL);

	read(handle_open, &output_buff[0], 4096);

	strcat(&open_file[0], &output_buff[0]);

	cmds[x] = strtok(output_buff, "\n");

	while (cmds[x] != NULL)
	{
		x++;
		cmds[x] = strtok(NULL, "\n");
	}
	run_opcodes(cmds);
	return (0);
}
