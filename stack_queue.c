#include "monty.h"
/**
 * stack - sets the format of the data to a stack
 * @last: Represents the stack
 * @line_number: Line with arguments to read
 * Return: Nothing is a void
 */
void stack(stack_t **last, unsigned int line_number)
{
	is_stack = 1;
	(void)last;
	(void)line_number;
}
/**
 * queue - sets the format of the data to a queue
 * @last: Represents the stack
 * @line_number: Line with arguments to read
 * Return: Nothin is a void
 */
void queue(stack_t **last, unsigned int line_number)
{
	is_stack = 0;
	(void)last;
	(void)line_number;
}
