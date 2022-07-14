#include "monty.h"

/**
 * nop - does nothing
 * @stack: top of the stack
 * @line: line number
 */
void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}

/**
 * qpush - adds a value to the queue
 * @stack: top of the stack
 * @line: line number
 */
void qpush(stack_t **stack, unsigned int line)
{
	stack_t *new;
	stack_t *temp;

	(void) line;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		freestack(stack);
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	value = (*stack)->n;
}
