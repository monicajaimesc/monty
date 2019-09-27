#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @top: Double pointer to the structure
 * @line: The line to be executed
 * Return: void
 */

void add(stack_t **last, unsigned int line_number)
{
	stack_t *new_last;

	if (*last == NULL || (*last)->next == NULL)
		add_error(line_number);

	new_last = (*last)->next;
	new_last->n += (*last)->n;
	pop(last, line_number);
}

