#include "monty.h"
/**
 * stack_push - Insertion of an element
 * @last: top of stack
 * Return: nothing, is void
*/
void stack_push(stack_t **last)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		malloc_error();
	}
	new_node->n = 0;
	new_node->prev = NULL;

	if (*last == NULL)
	{
		new_node->next = NULL;
		*last = new_node;
		return;
	}
	new_node->next = (*last);
	(*last)->prev = new_node;
	*last = new_node;
}
/**
 * pop_instruction - delete elements in the stack
 * @last: last bytes top's tack
 * @line_number: word, line
 * Return: nothing, is void
*/
void pop_instruction(stack_t **last, unsigned int line_number)
{
	stack_t *node = *last;

	if (*last == NULL)
		pop_error(line_number);
	*last = (*last)->next;
	free(node);
}
