#include "monty.h"

/**
* pall - prints all the values on the stack starting from the top.
* @head: Address of first node of the stack.
* Return: void
*/
void pall(stack_t *head)
{
	char str[4096] = {'\0'};

	while (head != NULL)
	{
		itoa(head->n, &str[0]);
		write(STDOUT_FILENO, str, _strlen(str));
		write(STDOUT_FILENO, "\n", 1);
		head = head->next;
	}
}
/**
* push - function that adds a new node to the top of the stack.
* @head: Pointer to address of first node.
* @n: Data that the added node will carry.
* Return: void
*/
void push(stack_t **head, int n)
{
	stack_t *new_node = NULL;
	stack_t *cur = *head;

	if (*head == NULL)
	{
		*head = create_node(n);
		return;
	}
	new_node = create_node(n);
	cur->prev = new_node;
	new_node->next = cur;
	*head = new_node;
}
