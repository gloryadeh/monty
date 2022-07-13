#include "monty.h"

/**
 * freestack - frees a stack
 * @stack: stack to free
 * @line: current line number
 */
void freestack(stack_t **stack, unsigned int line)
{
	if (stack == NULL)
		return;
	while (*stack != NULL)
		pop(stack, line);
}
