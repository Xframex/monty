#include "monty.h"

/**
 * div_m - top node by the top element of the stack.
 * @stack: head of linked list
 * @num_line: line number of the instruction
 */
void div_m(stack_lt **stack, unsigned int num_line)
{

	stack_lt *temp = NULL;
	stack_lt *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(num_line, "div");
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
		free_dlistint(*stack), op_e(num_line, "div");
	else
	{
		if (temp->n == 0)
			div_e(num_line);
		temp2->n = temp2->n / temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}



}
/**
 * mod_m - mod 2dn top node  top element of the stack.
 * @stack: head of linkedlist
 * @num_line: line number of routine

 */
void mod_m(stack_lt **stack, unsigned int num_line)
{

	stack_lt *temp = NULL;
	stack_lt *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		op_e(num_line, "mod");
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
		free_dlistint(*stack), op_e(num_line, "mod");
	else
	{
		if (temp->n == 0)
			div_e(num_line);
		temp2->n = temp2->n % temp->n;
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}

/**
 * pstr_t - prints the string starting at the top of the stack
 * @stack: head of linkedlist
 * @num_line: line number of the instruction
 */
void pstr_t(stack_lt **stack, unsigned int num_line)
{
	stack_lt *temp = NULL;
	(void)num_line;

	if (*stack == NULL || stack == NULL)
	{
		printf("\n");
		free_glovar();
		exit(0);
	}
	temp = *stack;
	if (temp->next == NULL && num_line == 2 && (temp->n < 0 || temp->n >= 127))
	{
		printf("\n");
		free_dlistint(*stack);
		free_glovar();
		exit(0);
	}
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		if (temp->n > 0 && temp->n < 127)
		{
			printf("%c", temp->n);
			temp = temp->prev;
		}
		else
			temp = temp->prev;
		if (temp->n <= 0 || temp->n >= 127)
		{
			printf("\n");
			return;
		}
	}
	printf("%c\n", temp->n);
}
/**
 * rotrl - rotate to left
 * @stack: head of linkedlist
 * @num_line: line number of the instruction
 */
void rotrl(stack_lt **stack, unsigned int num_line)
{

	stack_lt *temp2 = NULL;
	stack_lt *temp = NULL;
	(void)num_line;

	if (*stack == NULL || ((*stack)->next == NULL))
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp2 = temp->prev;
	temp2->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
/**
 * rotr - rotate to left
 * @stack: head of linkedlist
 * @num_line: line number of the instruction
 */
void rotr(stack_lt **stack, unsigned int num_line)
{
	stack_lt *temp2 = NULL;
	(void)num_line;

	if (*stack == NULL)
		return;
	temp2 = *stack;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = *stack;
	(*stack)->prev = temp2;
	temp2 = (*stack)->next;
	(*stack)->next = NULL;
	*stack = temp2;
	(*stack)->prev = NULL;
}

