#include "monty.h"

/**
* pall - prints all the values on the stack starting from the top.
* @head: Address of first node of the stack.
* Return: void
*/
void pall(stack_t *head)
{
	if (head != NULL)
	{
		pall(head->next);
		write(STDOUT_FILENO, itoa(head->n), _strlen(itoa(head->n)));
		write(STDOUT_FILENO, "\n", 1);
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
	while (cur != NULL)
	{
		if (cur->next == NULL)
		{
			new_node = create_node(n);
			cur->next = new_node;
			new_node->prev = cur;
			break;
		}
		cur = cur->next;
	}
}
