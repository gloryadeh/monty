#include "monty.h"

int value;

/**
 * isnum - checks if string is a number
 * @str: string to check
 *
 * Return: 1 if string is a number, 0 otherwise
 */
int isnum(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * getop - compares token and opcode
 * @token: token received
 * @stack: pointer to the stack
 * @line: line count
 */
void getop(char *token, stack_t **stack, unsigned int line)
{
	int i = 0;
	/* static char data; 0 for stack 1 for queue */

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(token, op[i].opcode) == 0)
		{
			op[i].f(stack, line);
			return;
		}
	}
	printf("L%d: unknown instruction %s\n", line, token);
	freestack(stack);
	exit(EXIT_FAILURE);
}
/**
 * gettoken - parses strings and gets tokens
 * @str: pointer to string
 * @stack: pointer to the stack
 * @line: line count
 */
void gettoken(char *str, stack_t **stack, unsigned int line)
{
	char *token;
	char *vtoken;

	token = strtok(str, " ");
	/* skip empty lines or lines starting with # */
	if (token == NULL || *token == '\n' || *token == ' ' || *token == '#')
		return;
	if (strcmp(token, "push") == 0)
	{
		/* check to ensure its int */
		vtoken = token;
		token = strtok(NULL, " ");
		if (!isnum(token))
		{
			printf("L%d: usage: push integer\n", line);
			freestack(stack);
			exit(EXIT_FAILURE);
		}
		value = atoi(token);
		getop(vtoken, stack, line);
	}
	else
		getop(token, stack, line);
}

/**
 * readfile - reads a text file
 * @file: file to be read
 */
void readfile(char *file)
{
	FILE *fp;
	char *buffer = NULL, *str;
	size_t size = 0;
	unsigned int line = 1;
	stack_t *stack = NULL;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, fp) != -1)
	{
		if (*buffer != '\n')
		{
			str = strtok(buffer, "\n");
			gettoken(str, &stack, line);
		}
		line++;
	}
	fclose(fp);
	free(buffer);
	if (stack != NULL)
		freestack(&stack);
}
