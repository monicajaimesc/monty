#ifndef HOLBERTON
#define HOLBERTON

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define USAGE "USAGE: monty file\n"

/* 1 stack, 0 queue */
extern int is_stack;
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

int is_a_number(char *s);
void free_all(stack_t **top, char *buff, FILE *fp);

void queue_push(stack_t **front);
void queue_pop(stack_t **front, unsigned int line);
void stack_push(stack_t **last);
void pop_instruction(stack_t **last, unsigned int line_number);

/* opcode execution */
void execute_opcode(char *token, stack_t **top, unsigned int line);
void push(stack_t **last, unsigned int line_number);
void pall(stack_t **last, unsigned int line_number);
void pint(stack_t **last, unsigned int line_number);
void pop(stack_t **last, unsigned int line_number);
void swap(stack_t **last, unsigned int line_number);
void add(stack_t **top, unsigned int line);
void nop(stack_t **top, unsigned int line);
void stack(stack_t **top, unsigned int line);
void queue(stack_t **top, unsigned int line);
/* error handler functions */
void push_error(unsigned int);
void usage_error(void);
void open_error(char *file);
void invalid_error(char *opcode, unsigned int line);
void malloc_error(void);
void empty_stack_pint(unsigned int);
void pop_error(unsigned int);
void swap_less_two(unsigned int);
void add_error(unsigned int);
int is_stack;
#endif
