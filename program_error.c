#include "monty.h"

/**
 * usage_error - How the progam works
 * void: Return
 * Return: void
 */

void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * open_error - The errors about open files
 * @file: The file to open
 * Return: void
 */

void open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * invalid_error - Unknown instructions
 * @opcode: The function´s parameter
 * @line: The line executed
 * Return: void
 */

void invalid_error(char *opcode, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, opcode);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - Handle error when malloc failed
 * void: Return nothing
 * Return: void
 */

void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * empty_stack_pint - Handle error when stack is empty
 * @line: The line executed
 * Return: void
 */

void empty_stack_pint(unsigned int line)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line);
	exit(EXIT_FAILURE);
}
