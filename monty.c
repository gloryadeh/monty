#include "monty.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument list
 * Return: not sure yet
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	readfile(argv[1]);

	return (0);
}
