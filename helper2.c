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
	if (!isascii(value))
	{
		printf("L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", value);
}

/**
 * pstr - prints the string starting at top of stack
 * @stack: stack to free
 * @line: current line number
 */
void pstr(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	temp = *stack;
	while (temp != NULL && temp->n != 0 && isascii(temp->n))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * top element becomes last and second top becomes top
 * @stack: stack to free
 * @line: current line number
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next->next = NULL;
}

/**
 * rotr - rotates the stack to the top
 * last element becomes the top element
 * @stack: stack to free
 * @line: current line number
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
}
