#include "monty.h"

/**
 * pop - Add node to the stack
 * @stack: head of linkedlist
 * @num_line: line number of the instruction
 *
 * Return: No return
 */
void pop(stack_lt **stack, unsigned int num_line)
{

	stack_lt *temp = NULL;
	stack_lt *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (stack == NULL)
	{
		free_dlistint(*stack);
		pop_elem(num_line); }
	if (*stack == NULL)
	{
		free_dlistint(*stack);
		pop_elem(num_line); }
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
	{

		free(*stack);
		*stack = NULL;
		return;
	}
	else
	{
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}
/**
 * add - adds the top two elements of the stack
 * @stack: head of linkedlist
 * @num_line: line number of the instruction
 */
void add(stack_lt **stack, unsigned int num_line)
{
	stack_lt *temp = NULL;
	stack_lt *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(num_line, "add");
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_dlistint(*stack), op_e(num_line, "add");
	else
	{
		temp2->n = temp2->n + temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}

}
/**
 * sub - subtracts the top e of stack from the 2nd top element of the stack.
 * @stack: head of linkedlist
 * @num_line: line number of the instruction
 */

void sub(stack_lt **stack, unsigned int num_line)
{

	stack_lt *temp = NULL;
	stack_lt *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(num_line, "sub");
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_dlistint(*stack), op_e(num_line, "sub");
	else
	{
		temp2->n = temp2->n - temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}
/**
 * mul - Mul 2nd val from top of a stack_lt by top value.
 * @stack: head of linkedlist
 * @num_line: line number of the instruction
 */
void mul(stack_lt **stack, unsigned int num_line)
{

	stack_lt *temp = NULL;
	stack_lt *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(num_line, "mul");
		return;
	}

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_dlistint(*stack), op_e(num_line, "mul");
	else
	{
		temp2->n = temp2->n * temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}

}
/**
 * pchar - Print char.
 * @stack: head of linkedlist
 * @num_line: line number of the instruction
 */
void pchar(stack_lt **stack, unsigned int num_line)
{

	stack_lt *temp;

	if (*stack == NULL || stack == NULL)
	{
		pchar_elem(num_line, "stack empty");
		return;
	}
	temp = (*stack);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp->n < 0 || temp->n > 127)
	{
		pchar_elem(num_line, "value out of range");
	}
	printf("%c\n", temp->n);
}

