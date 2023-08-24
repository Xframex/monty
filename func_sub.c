#include "monty.h"

/**
 * func_sub - sub top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @num_line: number of line opcode occurs on
 */
void func_sub(stack_tlin **stack, unsigned int num_line)
{
	stack_tlin *tmp = *stack;
	int sub = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	func_pop(stack, num_line);

	(*stack)->n = sub;
}

/**
 * func_mul - mul top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @num_line: number of line opcode occurs on
 */
void func_mul(stack_tlin **stack, unsigned int num_line)
{
	int aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", num_line);
		free(global_var.buffer);
		fclose(global_var.file);
		free_lis(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		aux = (*stack)->n;
		func_pop(stack, num_line);
		(*stack)->n *= aux;
	}
}


/**
 * func_div - div top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @num_line: number of line opcode occurs on
 */
void func_div(stack_tlin **stack, unsigned int num_line)
{
	int div = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", num_line);
		free(global_var.buffer);
		fclose(global_var.file);
		free_lis(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_line);
		free(global_var.buffer);
		fclose(global_var.file);
		free_lis(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*stack)->n;
		func_pop(stack, num_line);
		(*stack)->n /= div;
	}
}


/**
 * func_mod - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @num_line: number of line opcode occurs on
 */
void func_mod(stack_tlin **stack, unsigned int num_line)
{
	int mod = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", num_line);
		free(global_var.buffer);
		fclose(global_var.file);
		free_lis(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_line);
		free(global_var.buffer);
		fclose(global_var.file);
		free_lis(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mod = (*stack)->n;
		func_pop(stack, num_line);
		(*stack)->n %= mod;
	}
}

