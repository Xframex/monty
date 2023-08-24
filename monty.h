#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>


#define QUEUE 1
#define STACK 0
#define DELIM " \n\t\a\b"

/**
 * globales- struct  var global
 * @token2: integer
 * @fd: points to previous element of the stack
 * @line_buf: points to  next element of the stack
 *
 * Description: doubly linked list node
 * for stack, queues, LIFO, FIFO
 */
typedef struct globales_s
{
	char *token2;
	FILE *fd;
	char *line_buf;

} globales_t;

extern globales_t globalvar;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_lt;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_lt **stack, unsigned int num_line);
} instruction_t;

/* main.c */
int main(int argc, char **argv);

/* node function */
stack_lt *create_node_stackfirst(stack_lt **stack, int n);
stack_lt *create_node_stackend(stack_lt **stack, int n);
void free_node_stack(stack_lt **stack);

/*  */
int get_builtin(char *token, stack_lt **stack, unsigned int num_line);
/* */
void push(stack_lt **stack, unsigned int num_line);
void pall(stack_lt **stack, unsigned int num_line);
void pop(stack_lt **stack, unsigned int num_line);
void add(stack_lt **stack, unsigned int num_line);
void nop(stack_lt **stack, unsigned int num_line);
void sub(stack_lt **stack, unsigned int num_line);
void pint(stack_lt **stack, unsigned int num_line);
void swap(stack_lt **stack, unsigned int num_line);
void pchar(stack_lt **stack, unsigned int num_line);
void mul(stack_lt **stack, unsigned int num_line);
void div_m(stack_lt **stack, unsigned int num_line);
void mod_m(stack_lt **stack, unsigned int num_line);
void pstr_t(stack_lt **stack, unsigned int num_line);
void rotrl(stack_lt **stack, unsigned int num_line);





/*error routine*/
void stderr_usage(void);
void stderr_malloc(void);
void stderr_fopen(char *fd);
void stderr_int(unsigned int num_line);
void stderr_unknown(char *token, unsigned int num_line);
void div_e(unsigned int num_line);
void op_e(unsigned int num_line, char *op);
/* test functions */

void tokerr(int error_code);
unsigned int array_len(void);
char *get_int(int num);
unsigned int abs_m(int);
int len_buff_uint(unsigned int num, unsigned int base);
void full_buff(unsigned int num, unsigned int base, char *buff, int buff_size);
void pop_elem(unsigned int num_line);
void pint_elem(unsigned int num_line);
void pchar_elem(unsigned int num_line, char *msg);
int _isdigit();
void free_dlistint(stack_lt *stack);
void free_glovar(void);
void rotr(stack_lt **stack, unsigned int num_line);
stack_lt *add_dnodeint(stack_lt **head, int n);

/* UNUSED F
void pop(stack_lt **stack, unsigned int num_line);
void pint(stack_lt **stack, unsigned int num_line);
int cmd_monty(FILE *fd);
void free_tok(void);
int check_delim(char stream, char *delim);
int wstrlen(char *str, char *delim);
int wcounter(char *str, char *delim);
char **strtow(char *str, char *delim);
char *wnext(char *str, char *delim);
int create_node_stack(stack_lt **stack);
void free_node_stack(stack_lt **stack);
int no_line(char *line, char *delim);
int check_opcode(stack_lt *stack);
*/



#endif

