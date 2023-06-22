#include "monty.h"

/**
* add - function that adds top 2 element of the stack.
* @head: first node of the stack.
* @line_number: line where command is found.
* Return: void.
*/
void add(stack_t **head, unsigned int line_number)
{
	char err[4096] = {'\0'}, num[4096] = {'\0'};
	stack_t *cur = *head, *tmp = cur->next, *new_node = NULL;

	if (cur == NULL || cur->next == NULL)
	{
		strcat(&err[0], "L");
		strcat(&err[strlen(err)], itoa(line_number, &num[0]));
		strcat(&err[strlen(err)], ": can't add, stack too short\n");
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	new_node = create_node(cur->n + tmp->n);
	new_node->next = tmp->next;
	*head = new_node;
	free(cur);
	free(tmp);
}
/**
* sub - function that subtracts top 2 element of the stack.
* @head: first node of the stack.
* @line_number: line where command is found.
* Return: void.
*/
void sub(stack_t **head, unsigned int line_number)
{
	char err[4096] = {'\0'}, num[4096] = {'\0'};
	stack_t *cur = *head, *tmp = cur->next, *new_node = NULL;

	if (cur == NULL || cur->next == NULL)
	{
		strcat(&err[0], "L");
		strcat(&err[strlen(err)], itoa(line_number, &num[0]));
		strcat(&err[strlen(err)], ": can't sub, stack too short\n");
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	new_node = create_node(tmp->n - cur->n);
	new_node->next = tmp->next;
	*head = new_node;
	free(cur);
	free(tmp);
}
/**
* mul - function that multiplies top 2 element of the stack.
* @head: first node of the stack.
* @line_number: line where command is found.
* Return: void.
*/
void mul(stack_t **head, unsigned int line_number)
{
	char err[4096] = {'\0'}, num[4096] = {'\0'};
	stack_t *cur = *head, *tmp = cur->next, *new_node = NULL;

	if (cur == NULL || cur->next == NULL)
	{
		strcat(&err[0], "L");
		strcat(&err[strlen(err)], itoa(line_number, &num[0]));
		strcat(&err[strlen(err)], ": can't mul, stack too short\n");
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	new_node = create_node(cur->n * tmp->n);
	new_node->next = tmp->next;
	*head = new_node;
	free(cur);
	free(tmp);
}
/**
* op_div - function that adds top 2 element of the stack.
* @head: first node of the stack.
* @line_number: line where command is found.
* Return: void.
*/
void op_div(stack_t **head, unsigned int line_number)
{
	char err[4096] = {'\0'}, num[4096] = {'\0'};
	stack_t *cur = *head, *tmp = cur->next, *new_node = NULL;

	if (cur == NULL || cur->next == NULL)
	{
		strcat(&err[0], "L");
		strcat(&err[strlen(err)], itoa(line_number, &num[0]));
		strcat(&err[strlen(err)], ": can't div, stack too short\n");
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	if (cur->n == 0)
	{
		strcat(&err[0], "L");
		strcat(&err[strlen(err)], itoa(line_number, &num[0]));
		strcat(&err[strlen(err)], ": division by zero\n");
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	new_node = create_node(tmp->n / cur->n);
	new_node->next = tmp->next;
	*head = new_node;
	free(cur);
	free(tmp);
}
/**
* mod - function that adds top 2 element of the stack.
* @head: first node of the stack.
* @line_number: line where command is found.
* Return: void.
*/
void mod(stack_t **head, unsigned int line_number)
{
	char err[4096] = {'\0'}, num[4096] = {'\0'};
	stack_t *cur = *head, *tmp = cur->next, *new_node = NULL;

	if (cur == NULL || cur->next == NULL)
	{
		strcat(&err[0], "L");
		strcat(&err[strlen(err)], itoa(line_number, &num[0]));
		strcat(&err[strlen(err)], ": can't mod, stack too short\n");
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	if (cur->n == 0)
	{
		strcat(&err[0], "L");
		strcat(&err[strlen(err)], itoa(line_number, &num[0]));
		strcat(&err[strlen(err)], ": division by zero\n");
		write(STDERR_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	new_node = create_node(tmp->n % cur->n);
	new_node->next = tmp->next;
	*head = new_node;
	free(cur);
	free(tmp);
}
