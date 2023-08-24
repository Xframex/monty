#include "monty.h"

/**
 * func_pstr - top of stack
 * @stack: pointer to lists  monty stack
 * @num_line: number of line opcode occurs on
 */
void func_pstr(stack_tlin **stack, unsigned int num_line)
{
	stack_tlin *tmp = *stack;
	int c = 0;

	(void)num_line;

	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || isalphabi(c) == 0)
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}


/**
 * func_rot - mod top of stack  second top stack
 * @stack: pointer to lists  monty stack
 * @num_line: number of  opcode  on
 */
void func_rot(stack_tlin **stack, unsigned int num_line)
{
	stack_tlin *runner = *stack;
	int aux1 = 0;

	if (!num_line || !stack || !*stack || !(*stack)->next)
		return;

	aux1 = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = aux1;
}



/**
 * func_rotr - mod top of  second top stacks
 * @stack: pointer to lists for  stack
 * @num_line: numb of line opcode occurs on
 */
void func_rotr(stack_tlin **stack, unsigned int num_line)
{
	stack_tlin *runner = *stack;
	int aux1 = 0;

	if (!num_line || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
		runner = runner->next;

	aux1 = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = aux1;
}


