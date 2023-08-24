#include "monty.h"

/**
 * func_push - push  to stack
 * @stack: linked lists for monty stack
 * @num_line: number of line opcode occurs on
 */
void func_push(stack_tlin **stack, __attribute__ ((unused))unsigned int num_line)
{
	stack_tlin *top;
	(void)num_line;

	top = malloc(sizeof(stack_tlin));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = global_var.push_var;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}



/**
 * func_pall -  function
 * @stack: pointer to linked list stack
 * @num_line: number of line opcode  on
 */
void func_pall(stack_tlin **stack, __attribute__ ((unused))unsigned int num_line)
{
	stack_tlin *runner;

	runner = *stack;

	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}



/**
 * func_pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @num_line: number of line opcode occurs 
 *
 */
void func_pint(stack_tlin **stack, unsigned int num_line)
{
	stack_tlin *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * func_pop - poping  element a list
 *@stack: pointer to first node
 *@num_line: integer
 *Return: void
 */
void func_pop(stack_tlin **stack, unsigned int num_line)
{
	stack_tlin *node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num_line);
		exit(EXIT_FAILURE);
	}
	*stack = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node);
}


/**
 * free_lis - free a list
 * @head: pointer to first node
 *
 */
void free_lis(stack_tlin *head)
{
	stack_tlin *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
