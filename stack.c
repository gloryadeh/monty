#include "monty.h"

/**
 * push - adds a value to the start of a list
 * @stack: top of the stack
 * @line: line number
 */
void push(stack_t **stack, unsigned int line)
{
	stack_t *top;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		printf("Error: malloc failed\n");
		freestack(stack, line);
		exit(EXIT_FAILURE);
	}
	top->n = value;
	top->prev = NULL;
	top->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * pall - prints all the values in the stack
 * @stack: top of the stack
 * @line: line number
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *temp;

	if (stack == NULL)
	{
		return;
	}
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop - removes top element in the stack
 * @stack: top of the stack
 * @line: line number
 */
void pop(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		value = (*stack)->n;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * pint - removes top element in the stack
 * @stack: top of the stack
 * @line: line number
 */
void pint(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * swap - swaps top two elements of a stack
 * @stack: top of the stack
 * @line_number: current line number
 *
 * Return: deleted node
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int val;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		freestack(stack, line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	val = temp->next->n;
	temp->next->n = temp->n;
	temp->n = val;

}
