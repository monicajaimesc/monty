#include "monty.h"

/**
 * push_error - Handle error if there is not an integer or not argument given
 * @line: The function´s parameter
 * Return: Void
 */

void push_error(unsigned int line)
{
	fprintf(stderr, "L%u: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}


/**
 * pop_error - Handle error for deletion of an empty stack
 * @line: The function´s parameter
 * Return: void
 */

void pop_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line);
	exit(EXIT_FAILURE);
}

/**
 * swap_less_two - last 2 bytes cant swap.
 * @line: The function´s parameter
 * Return: void
 */

void swap_less_two(unsigned int line)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line);
	exit(EXIT_FAILURE);
}
/**
 * add_error - Error when can´t add.
 * @line: The function´s parameter
 * Return: void
 */

void add_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * sub_error - Error when can´t do subtraction
 * @line: The function´s parameter
 * Return: void
 */

void sub_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line);
	exit(EXIT_FAILURE);
}
