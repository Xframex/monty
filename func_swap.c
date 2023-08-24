#include "monty.h"

/**
 * func_swap - swap top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @num_line: number of line opcode occurs on
 */

void func_swap(stack_tlin **stack, unsigned int num_line)
{
	stack_tlin *runner;
	int tmp;

	runner = *stack;
	if (runner == NULL || runner->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}


/**
 * func_add - add top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @num_line: number of line opcode occurs on
 */
void func_add(stack_tlin **stack, unsigned int num_line)
{
	stack_tlin *tmp = *stack;
	int sum = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	func_pop(stack, num_line);

	(*stack)->n = sum;
}



/**
 * func_nop - nop top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @num_line: number of line opcode occurs on
 */

void func_nop(__attribute__ ((unused))stack_tlin **stack,
	  __attribute__ ((unused)) unsigned int num_line)
{
	;
}


/**
 * func_pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @num_line: the index of the current line
 *
 */
void func_pchar(stack_tlin **stack, unsigned int num_line)
{
	int val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num_line);
		free(global_var.buffer);
		fclose(global_var.file);
		free_lis(*stack);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;

	if (val > 127 || val < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num_line);
		free(global_var.buffer);
		fclose(global_var.file);
		free_lis(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n');
}


/**
 * isalphabi - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int isalphabi(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}

