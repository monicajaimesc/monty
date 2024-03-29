#include "monty.h"

/**
 * main - Interpreter for monty files
 * @argc: will be given for the stack and queue
 * @argv: pointer to the structure
 * Return: void
 */
int main(int argc, char *argv[])
{
	FILE *file_name;
	char *buffer = NULL, *word = NULL, *empty_line = NULL;
	unsigned int line_number = 1;
	size_t bytes = 1024;
	stack_t *last = NULL, *current = NULL;
	

	is_stack = 1;
	/* different of 2 because to be able to execute the program */
	if (argc != 2)
		usage_error();
	/* r - open for reading */
	/* open monty_file.m */
	file_name = fopen(argv[1], "r");
	if (!file_name)
		open_error(argv[1]);
		/*EOF end of a file */
	while (getline(&buffer, &bytes, file_name) != EOF)
	{
		word = strtok(buffer, " \n");
		/* \n because is one arik3ecv ber of spaces before-after the opcode and argument*/
		empty_line = strtok(NULL, " \n");
		/* Just need to read the arguments*/
		if (!word || word[0] == '#')
		{
			line_number++;
			continue;
		}
		execute_opcode(word, &last, line_number);
/* Executes the opcode, filling the stack*/
/* opcode is the first byte of an instruction in machine language*/
		if (strcmp(word, "push") == 0) /* if the comparation happen because is 0*/
		{
			if (empty_line == NULL || is_a_number(empty_line) == -1)
				push_error(line_number);
			if (is_stack == 1)
				last->n = atoi(empty_line);
			else
			{
				current = last;
				while (current->next)
					current = current->next;
				current->n = atoi(empty_line);
			}
		}
		line_number++;
	}
	free_all(&last, buffer, file_name);
	return (EXIT_SUCCESS);
}
/**
 * execute_opcode - select correct function to perform operation
 * @s: operator passed as argument to the program
 * @last: stack
 * @line: line of the instruction
 * Return: void
 */
void execute_opcode(char *s, stack_t **last, unsigned int line_number)
{
	int idx, len;
/*array of structure of op_t and it has 2 members*/
 /*char *op and int *f (int, int)*/
	instruction_t opcodes[] = {
/*0*/	{"push", push},
/*1*/	{"pall", pall},
/*2*/	{"pint", pint},
/*3*/	{"pop", pop},
/*4*/	{"swap", swap},
/*5*/	{"add", add},
/*6*/	{"nop", nop},
/*7*/	{"stack", stack},
/*8*/	{"queue", queue}
	};
	len = (int)(sizeof(opcodes) / sizeof(instruction_t));
	for (idx = 0; idx< len; idx++)
	{
		if (strcmp(s, opcodes[idx].opcode) == 0) /* compare */
		{
			opcodes[idx].f(last, line_number); /* acces to structure content to compare */
			return; /* come back loop */
		}
	}
	invalid_error(s, line_number);
}
/*function that will return a pointer a una funcion que recibe dos parametros y esa funcion me retorna un int*/

/**
 * is_a_number - test if a string is a number
 * @s: string
 * Return: -1 if not number, 1 otherwise
 */
int is_a_number(char *s)
{
	int i = 0;

	if (!s)
		return (-1);

	while (s[i])
	{
		if (s[i] != 45 && isdigit(s[i]) == 0)
			return (-1);
		i++;
	}
	return (1);
}
/**
 * free_all - frees and close files
 * @top: top of stack
 * @buff: string buffer
 * @fp: file descriptor
 * Return: void
 */
void free_all(stack_t **last, char *buffer, FILE *file_name)
{
	stack_t *temporal = NULL;

	while (*last != NULL)
	{
		temporal = *last;
		*last = (*last)->next;
		free(temporal);
	}
	free(buffer);
	fclose(file_name);
}
