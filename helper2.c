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

/**
 * pchar - prints the char at the top of the stack
 * @stack: stack to free
 * @line: current line number
 */
void pchar(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	if (value < 0 || value > 127)
	{
		printf("L%d: can't pchar, value out of range\n", line);
		freestack(stack, line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", value);
}

/**
 * pstr - prints the string starting at top of stack
 * @stack: stack to free
 * @line: current line number
 */
void pstr(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line);
		freestack(stack, line);
		exit(EXIT_FAILURE);
	}
	while ((*stack)->n != 0)
	{
		if ((*stack)->n > 127)
		{
			freestack(stack, line);
			break;
		}
		printf("%c", (*stack)->n);
		*stack = (*stack)->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * @stack: stack to free
 * @line: current line number
 */
/*void rotl(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line);
		freestack(stack, line);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

}
*/
