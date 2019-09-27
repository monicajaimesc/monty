#include "monty.h"

/**
 * swap - swaps 2 bytes at the stack's top
 *@last: last bytes of top, doubler pointer
 *@line_number: line number of the instruction
 * Return: nothing, is a void
 */
void swap(stack_t **last, unsigned int line_number)
{
	stack_t *row_1, *row_2, *row_3;

	if (*last == NULL || (*last)->next == NULL)
		swap_less_two(line_number);

	row_1 = *last;
	row_2 = (*last)->next;
	row_3 = row_2->next;
	*last = row_2;
	row_2->next = row_1;
	row_1->prev = row_2;
	row_1->next = row_3;
	if (row_3)
		row_3->prev = row_1;
}
/**
 * pop - removes element at top
 * @last: stack
 * @line_number: line of the instruction
 * Return: void
 */
void pop(stack_t **last, unsigned int line_number)
{
	if (is_stack == 1)
		pop_instruction(last, line_number);
	else
		queue_pop(last, line_number);
}
/**
 * pint - print bytes at the stack top
 * @last: last bytes at top
 * @line_number: line number of the instruction
 * Return: nothing, is void
 */
void pint(stack_t **last, unsigned int line_number)
{
	if (*last == NULL)
		empty_stack_pint(line_number);
	printf("%d\n", (*last)->n);
}
/**
 * pall - prints all elements of stack
 * @last: last bytes of the stack
 * @line_number: line number of the instruction
 * Return: void
 */
void pall(stack_t **last, unsigned int line_number)
{
	stack_t *current = *last;

	if (*last == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}
/**
 * push - insert a new byte in the stack
 * @last: last bytes on top of the stack
 * @line_number: line of the instruction
 * Return: nothing, is void
 */
void push(stack_t **last, unsigned int line_number)
{
	if (is_stack == 1)
		stack_push(last);
	else
		queue_push(last);
	(void)line_number;
}
