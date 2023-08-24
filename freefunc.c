#include "monty.h"

/**
 * free_dlistint - free a dlistint_t list.
 * @stack: pointer to the first element of the list
 * Return: no return
 */
void free_dlistint(stack_lt *stack)
{
	stack_lt *aux = NULL;
	stack_lt *temp = NULL;

	temp = stack;
	while (temp != NULL)
	{
		aux = temp->next;
		free(temp);
		temp = aux;
	}
	stack = NULL;
}

/**
 * free_glovar - free a dlistint_t list.
 *
 * Return: no return
 */
void free_glovar(void)
{
	fclose(globalvar.fd);
	free(globalvar.line_buf);
}

