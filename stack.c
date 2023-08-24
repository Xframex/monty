#include "monty.h"

/**
 * create_node_stack - create a node stack.
 * @stack: A pointer to top and bottom stack.
 * Return: EXIT SUCCESS
 */
int create_node_stack(stack_lt **stack)
{
	stack_lt *p;

	p = malloc(sizeof(stack_lt));
	if (p == NULL)
		stderr_malloc();
	p->n = STACK;
	p->prev = NULL;
	p->next = NULL;

	*stack = p;

	return (EXIT_SUCCESS);
}
/**
 * free_node_stack - Frees a stack_lt stack.
 * @stack: A pointer to top and bottom stack.
 */
void free_node_stack(stack_lt **stack)
{
	stack_lt *temp_node = *stack;

	while (*stack)
	{
		temp_node = (*stack)->next;
		free(*stack);
		*stack = temp_node;
	}
}
/**
 * check_opcode - checks if STACK or QUEUE.
 * @stack: A pointer to top and bottom stack.
 * Return: The value of Stack or Queue
 */
int check_opcode(stack_lt *stack)
{
	int ret_val = 2;

	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (ret_val);
}

