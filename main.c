#include "monty.h"

/**
 * main - Interpreter for monty files
 * @argc: will be given for the stack and queue
 * @argv: pointer to the structure
 * Return: void
 */
int main(int argc, char *argv[])
{
	char *buff = NULL, *token1 = NULL, *token2 = NULL;
	size_t bytes = 1024;
	unsigned int line_count = 1;
	stack_t *top = NULL, *current = NULL;
	FILE *fp;

	is_stack = 1;
	/* different of 2 because to be able to execute the program */
	if (argc != 2)
		usage_error();
	/* r - open for reading */
	/* open monty_file.m */
	fp = fopen(argv[1], "r");
	if (!fp)
		open_error(argv[1]);
		/*EOF end of a file */
	while (getline(&buff, &bytes, fp) != EOF)
	{
		token1 = strtok(buff, " \n");
		/* \n because is one argument in one line */
		/* There can be any number of spaces before-after the opcode and argument*/
		token2 = strtok(NULL, " \n");
		/* Just need to read the arguments*/
		if (!token1 || token1[0] == '#')
		{
			line_count++;
			continue;
		}
		execute_opcode(token1, &top, line_count);
/* Executes the opcode, filling the stack*/ 
/* opcode is the first byte of an instruction in machine language*/
		if (strcmp(token1, "push") == 0) /* if the comparation happen because is 0*/
		{
			if (token2 == NULL || is_a_number(token2) == -1)
				push_error(line_count);
			if (is_stack == 1)
				top->n = atoi(token2);
			else
			{
				current = top;
				while (current->next)
					current = current->next;
				current->n = atoi(token2);
			}
		}
		line_count++;
	}
	free_all(&top, buff, fp);
	return (EXIT_SUCCESS);
}
/**
 * execute_opcode - execute the opcode found in the line
 * @token: opcode
 * @top: stack
 * @line: line of the instruction
 * Return: void
 */
void execute_opcode(char *token, stack_t **top, unsigned int line)
{
	int i, len;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"stack", stack},
		{"queue", queue}
	};
	len = (int)(sizeof(opcodes) / sizeof(instruction_t));
	for (i = 0; i < len; i++)
	{
		if (strcmp(token, opcodes[i].opcode) == 0) /* compare */
		{
			opcodes[i].f(top, line); /* acces to structure content to compare */
			return; /* come back loop */
		}
	}
	invalid_error(token, line);
}

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
void free_all(stack_t **top, char *buff, FILE *fp)
{
	stack_t *tmp = NULL;

	while (*top != NULL)
	{
		tmp = *top;
		*top = (*top)->next;
		free(tmp);
	}
	free(buff);
	fclose(fp);
}
