#include "monty.h"

/**
 * add - adds the two top elements of the stack
 * @stack: top of the stack
 * @line: line number
 */
void add(stack_t **stack, unsigned int line)
{
	int sum = 0;
	stack_t *temp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	pop(stack, line);
}

/**
 * sub - subtracts top element from the second top element
 * @stack: top of the stack
 * @line: line number
 */
void sub(stack_t **stack, unsigned int line)
{
	int result = 0;
	stack_t *temp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line);
		freestack(stack);
		exit(EXIT_FAILURE);
	}

	result = temp->next->n - temp->n;
	temp->next->n = result;
	pop(stack, line);
}

/**
 * divide - divides the second top element by the top element
 * @stack: top of the stack
 * @line: line number
 */
void divide(stack_t **stack, unsigned int line)
{
	int result = 0;
	stack_t *temp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line);
		freestack(stack);
		exit(EXIT_FAILURE);
	}
	result = temp->next->n / temp->n;
	temp->next->n = result;
	pop(stack, line);
}

/**
 * mul - multiplies the second top element with the top element
 * @stack: top of the stack
 * @line: line number
 */
void mul(stack_t **stack, unsigned int line)
{
	int result = 0;
	stack_t *temp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line);
		freestack(stack);
		exit(EXIT_FAILURE);
	}

	result = temp->next->n * temp->n;
	temp->next->n = result;
	pop(stack, line);
}

/**
 * mod - remainder of division of second to element
 * by top element
 * @stack: top of the stack
 * @line: line number
 */
void mod(stack_t **stack, unsigned int line)
{
	int result = 0;
	stack_t *temp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line);
		freestack(stack);
		exit(EXIT_FAILURE);
	}
	result = temp->next->n % temp->n;
	temp->next->n = result;
	pop(stack, line);
}
