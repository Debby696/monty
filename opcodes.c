#include "monty.h"

/**
* pall - prints all the values on the stack starting from the top.
* @head: Address of first node of the stack.
* @line_number: line where command is found.
* Return: void
*/
void pall(stack_t **head, unsigned int line_number)
{
	char str[4096] = {'\0'};
	stack_t *cur = *head;

	while (cur != NULL)
	{
		itoa(cur->n, &str[0]);
		write(STDOUT_FILENO, str, strlen(str));
		write(STDOUT_FILENO, "\n", 1);
		cur = cur->next;
		line_number--;
	}
}
/**
* push - function that adds a new node to the top of the stack.
* @head: Pointer to address of first node.
* @line_number: line where command is found.
* Return: void
*/
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL, *cur = *head;
	char *second_arg = NULL;

	_strtok(get_cmd(line_number), " ");
	second_arg = _strtok(NULL, " ");

	if (second_arg == NULL)
		handle_error(3, NULL, line_number, NULL);


	if (check_digit(second_arg) == 0 || atoi(second_arg) != 0)
	{
		if (*head == NULL)
		{
			*head = create_node(atoi(second_arg));
			return;
		}
		new_node = create_node(atoi(second_arg));
		cur->prev = new_node;
		new_node->next = cur;
		*head = new_node;
	}
	else
	{
		free_stack(*head);
		handle_error(3, NULL, line_number, NULL);
	}
}

/**
* pint - function that prints the val at the top of the stack.
* @head: first node of the stack.
* @line_number: line where command is found.
* Return: void.
*/
void pint(stack_t **head, unsigned int line_number)
{
	char str[4096] = {'\0'};
	stack_t *cur = *head;

	if (*head == NULL)
		handle_error(5, NULL, line_number, NULL);

	itoa(cur->n, &str[0]);
	write(STDOUT_FILENO, str, strlen(str));
	write(STDOUT_FILENO, "\n", 1);
}

/**
* pop - function that removes to element of the stack.
* @head: first node of the stack.
* @line_number: line where command is found.
* Return: void.
*/
void pop(stack_t **head, unsigned int line_number)
{
	char err[4096] = {'\0'}, num[4096] = {'\0'};
	stack_t *cur = *head;

	if (*head == NULL)
	{
		strcat(&err[0], "L");
		strcat(&err[strlen(err)], itoa(line_number, &num[0]));
		strcat(&err[strlen(err)], ": can't pop, stack empty\n");
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	cur = cur->next;
	free(*head);
	*head = cur;
}

/**
* swap - function that removes to element of the stack.
* @head: first node of the stack.
* @line_number: line where command is found.
* Return: void.
*/
void swap(stack_t **head, unsigned int line_number)
{
	char err[4096] = {'\0'}, num[4096] = {'\0'};
	stack_t *cur = *head, *tmp = cur->next;

	if (cur == NULL || cur->next == NULL)
	{
		strcat(&err[0], "L");
		strcat(&err[strlen(err)], itoa(line_number, &num[0]));
		strcat(&err[strlen(err)], ": can't swap, stack too short\n");
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	*head = tmp;
	cur->next = tmp->next;
	tmp->next = cur;
	cur->prev = tmp;
	tmp->prev = NULL;
}
