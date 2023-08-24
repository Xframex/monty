#include "monty.h"

/**
 * push - Add node to stack
 * @stack: head of linked list
 * @num_line: line number of the instruction
 *
 * Return: No return
 */
void push(stack_lt **stack, unsigned int num_line)
{

	int n = 0;

	if (globalvar.token2 == NULL)
	{
		free_dlistint(*stack);
		stderr_int(num_line);
	}
	if (!_isdigit() || stack == NULL)
	{
		free_dlistint(*stack);
		stderr_int(num_line);
	}
	n = atoi(globalvar.token2);
	if (*stack  == NULL)
	{
		create_node_stackfirst(stack, n);
	}
	else
	{
		create_node_stackend(stack, n);
	}
}

/**
 * pall - Print the stack
 * @stack: head of linkedlist
 * @num_line: line number of the instruction
 *
 * Return: No return
 */
void pall(stack_lt **stack, unsigned int num_line)
{

	stack_lt *temp = NULL;


	if (*stack == NULL)
	{
		return;
	}
	if (*stack == NULL && num_line != 1)
	{
		free_dlistint(*stack);
		free_glovar();
		exit(EXIT_SUCCESS);
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d", temp->n);
		temp = temp->prev;
		printf("\n");
	}
	printf("%d\n", temp->n);
}


/**
 * pint - Print the stack
 * @stack: head of linkedlist
 * @num_line: line number of the instruction
 *
 * Return: No return
 */
void pint(stack_lt **stack, unsigned int num_line)
{

	stack_lt *temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		pint_elem(num_line);
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	printf("%d", temp->n);
	printf("\n");
}

/**
 * swap - Print the stack
 * @stack: head of linkedlist
 * @num_line: line number of the instruction
 *
 * Return: No return
 */
void swap(stack_lt **stack, unsigned int num_line)
{
	stack_lt *temp;
	int i, j;

	if (*stack == NULL || stack == NULL)
		op_e(num_line, "swap");

	temp = (*stack)->next;
	if ((*stack)->next == NULL)
		op_e(num_line, "swap");
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	i = temp->n;
	j = temp->prev->n;
	temp->n = j;
	temp->prev->n = i;
}
/**
 * nop - does not do anything
 * @stack: head of linked list
 * @num_line: line number of routine
 *
 * Return: No return
 */
void nop(stack_lt **stack, unsigned int num_line)
{
	(void)stack;
	(void)num_line;
}

