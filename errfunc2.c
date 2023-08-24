#include "monty.h"

/**
 * pop_elem - pop error message for empty stacks.
 * @num_line: line number of the instructions.
 * Return: EXIT_FAILURE.
 */
void pop_elem(unsigned int num_line)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", num_line);
	free_glovar();
	exit(EXIT_FAILURE);
}

/**
 * pint_elem - pint error message for empty stacks.
 * @num_line: line number of the instruction.
 * Return: EXIT_FAILURE
 */
void pint_elem(unsigned int num_line)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", num_line);
	free_glovar();
	exit(EXIT_FAILURE);
}

/**
 * op_e - math func error messagess.
 * @num_line: line number of the instruction.
 * @op: Operation where the error occurred.
 * Return: EXIT_FAILURE
 */
void op_e(unsigned int num_line, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", num_line, op);
	free_glovar();
	exit(EXIT_FAILURE);
}
/**
 * pchar_elem - phar error msg for 0 stack & and non-char val.
 * @num_line: line number of the instruction
 * @msg: error message to print.
 * Return: EXIT_FAILURE.
 */
void pchar_elem(unsigned int num_line, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", num_line, msg);
	free_glovar();
	exit(EXIT_FAILURE);
}

/**
 * div_e - error for div by 0.
 * @num_line: line number of the instruction.
 * Return: EXIT_FAILURE
 */
void div_e(unsigned int num_line)
{
	fprintf(stderr, "L%u: division by zero\n", num_line);
	free_glovar();
	exit(EXIT_FAILURE);
}

