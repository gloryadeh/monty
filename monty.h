#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define _XOPEN_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

extern int value;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int isnum(char *str);
void nop(stack_t **stack, unsigned int line);
void freestack(stack_t **stack);

void getop(char *token, stack_t **stack, unsigned int line);
void readfile(char *filename);
void gettoken(char *str, stack_t **stack, unsigned int line);
void stack_queue(char *token, stack_t **stack, unsigned int line);

void pop(stack_t **stack, unsigned int line);
void pint(stack_t **stack, unsigned int line);
void swap(stack_t **stack, unsigned int line);
void push(stack_t **stack, unsigned int line);
void pall(stack_t **stack, unsigned int line);

void add(stack_t **stack, unsigned int line);
void sub(stack_t **stack, unsigned int line);
void divide(stack_t **stack, unsigned int line);
void mul(stack_t **stack, unsigned int line);
void mod(stack_t **stack, unsigned int line);

void pchar(stack_t **stack, unsigned int line);
void pstr(stack_t **stack, unsigned int line);

void rotl(stack_t **stack, unsigned int line);
void rotr(stack_t **stack, unsigned int line);

#endif
