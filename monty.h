#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int push_var;

/**
 * struct stack_nn - doubly linked list representation of a stack  queue
 * @n: integer
 * @prev: points to previous element of the stack or queue
 * @next: points to next element of the stack or queue)
 *
 * Des doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_nn
{
	int n;
	struct stack_nn *prev;
	struct stack_nn *next;
} stack_tlin;



/**
 * struct instruction_t - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_t
{
	char *opcode;
	void (*f)(stack_tlin **stack, unsigned int num_line);
} instruction_t;


/**
 * struct global_variables - store data global variables
 * @file: opcode
 * @push_var: value of push routine
 * @buffer: pointer to  value
 */
typedef struct global_variables
{
	FILE *file;
	int push_var;
	char *buffer;
} global_variable;

global_variable global_var;

void read_file(char *filename, stack_tlin **stack);
char *parse_line(char *line, stack_tlin **stack, unsigned int num_line);
typedef void (*instruct_func)(stack_tlin **stack, unsigned int num_line);
instruct_func get_op_func(char *s);

void func_pall(stack_tlin **stack, unsigned int num_line);
void func_push(stack_tlin **stack, unsigned int num_line);
void func_pint(stack_tlin **stack, unsigned int num_line);
void func_pop(stack_tlin **stack, unsigned int num_line);
void func_swap(stack_tlin **stack, unsigned int num_line);
void func_nop(stack_tlin **stack, unsigned int num_line);
void func_rot(stack_tlin **stack, unsigned int num_line);
void func_rotr(stack_tlin **stack, unsigned int num_line);

void func_pchar(stack_tlin **stack, unsigned int num_line);
void func_pstr(stack_tlin **stack, unsigned int num_line);


void func_sub(stack_tlin **stack, unsigned int num_line);
void func_add(stack_tlin **stack, unsigned int num_line);
void func_mul(stack_tlin **stack, unsigned int num_line);
void func_div(stack_tlin **stack, unsigned int num_line);
void func_mod(stack_tlin **stack, unsigned int num_line);

void free_lis(stack_tlin *head);
void lisfree(stack_tlin **stack);
void lisfree2(stack_tlin **stack);
int isalphabi(int c);

#endif /* MONTY_H */

