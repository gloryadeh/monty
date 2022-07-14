#include "monty.h"

/**
 * swap - swaps the two top elements of the stack
 * @stack: top of the stack
 * @line: line number
 */
void swap(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	temp->prev = *stack;
	temp->next = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack)->next = temp;
	if (temp->next != NULL)
		temp->next->prev = temp;
	value = (*stack)->n;
}

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
