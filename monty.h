#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
* struct value - holds value in global scope
* @value: actual value
*
* Description: to allow me to access this value globally
*/
typedef struct value
{
	int value;
} value_s;

extern value_s variable;
value_s variable;

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
} stack_t;

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
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* opening file */
char *file_open(char *file);

/*dlinkedlist.c*/
int add_end_node(stack_t **head, int n);
void del_end_node(stack_t **head);
void free_dlist(stack_t **head);

/*print.c*/
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);

/*pushpop.c*/
void push(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
/*calculator.c*/
void _add(stack_t **head, unsigned int line_number);
void _sub(stack_t **head, unsigned int line_number);

/* arithmetics.c */
void add(stack_t **stk, unsigned int linenum);

/* tokenizer */
void tokenizer(char *input, stack_t **stack, unsigned int line_number);

/* frees pointers to pointers */
void freer(char **buf);

/* execute */
void execute_ops(stack_t **stack, unsigned int line_number, char *token);

/* frees entire stack */
void free_stack(stack_t **stack, unsigned int line_number);

/* check for digit */
int check_digit(char *token);

#endif
