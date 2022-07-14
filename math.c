#include "monty.h"

/**
 * add - adds the two top elements of the stack
 * @stack: top of the stack
 * @line: line number
 */
void add(stack_t **stack, unsigned int line)
{
	int top;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't add, stack too short\n", line);
		freestack(stack, line);
		exit(EXIT_FAILURE);
	}

	top = value;
	pop(stack, line);
	top += value;
	pop(stack, line);
	value = top;
	push(stack, line);
}

/**
 * sub - subtracts top element from the second top element
 * @stack: top of the stack
 * @line: line number
 */
void sub(stack_t **stack, unsigned int line)
{
	int top;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line);
		freestack(stack, line);
		exit(EXIT_FAILURE);
	}

	top = value;
	pop(stack, line);
	top = value - top;
	pop(stack, line);
	value = top;
	push(stack, line);
}

/**
 * divide - divides the second top element by the top element
 * @stack: top of the stack
 * @line: line number
 */
void divide(stack_t **stack, unsigned int line)
{
	int top;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't div, stack too short\n", line);
		freestack(stack, line);
		exit(EXIT_FAILURE);
	}
	if (value == 0)
	{
		printf("L%d: division by 0\n", line);
		freestack(stack, line);
		exit(EXIT_FAILURE);
	}
	top = value;
	pop(stack, line);
	top = value / top;
	pop(stack, line);
	value = top;
	push(stack, line);
}

/**
 * mul - multiplies the second top element with the top element
 * @stack: top of the stack
 * @line: line number
 */
void mul(stack_t **stack, unsigned int line)
{
	int top;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line);
		freestack(stack, line);
		exit(EXIT_FAILURE);
	}

	top = value;
	pop(stack, line);
	top = value * top;
	pop(stack, line);
	value = top;
	push(stack, line);
}

/**
 * mod - remainder of division of second to element
 * by top element
 * @stack: top of the stack
 * @line: line number
 */
void mod(stack_t **stack, unsigned int line)
{
	int top;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't div, stack too short\n", line);
		freestack(stack, line);
		exit(EXIT_FAILURE);
	}
	if (value == 0)
	{
		printf("L%d: division by 0\n", line);
		freestack(stack, line);
		exit(EXIT_FAILURE);
	}
	top = value;
	pop(stack, line);
	top = value % top;
	pop(stack, line);
	value = top;
	push(stack, line);
}
