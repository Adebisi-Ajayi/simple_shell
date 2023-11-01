#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * read_line - Read a line of input from the user.
 *
 * Description: This function reads a line of input from the user and stores
 * it in a buffer. It returns the number of characters read.
 *
 * @buffer: The buffer to store the input.
 * @size: The size of the buffer.
 * Return: The number of characters read.
 */
ssize_t read_line(char *buffer, ssize_t size)
{
	ssize_t i = 0;
	int c;

	if (size == 0)
	{
		return (-1);
	}

	while ((c = getchar()) != EOF && c != '\n' && i < size - 1)
	{
		buffer[i] = c;
		i++;
	}

	if (c == '\n')
	{
		buffer[i] = c;
		i++;
	}

	buffer[i] = '\0';
	return (i);
}

/**
 * split_line - Split a line into arguments.
 *
 * Description: This function takes a line of input and splits it into
 * arguments based on space as a delimiter. The arguments are stored in
 * a dynamically allocated array.
 *
 * @line: The line of input to split.
 * @argc: A pointer to store the number of arguments.
 * Return: An array of argument strings.
 */
char **split_line(char *line, int *argc)
{
	int buffer_size = BUFFER_SIZE;
	int position = 0;
	char **tokens = malloc(buffer_size * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");
	while (token)
	{
		tokens[position] = strdup(token);
		position++;

		if (position >= buffer_size)
		{
			buffer_size += BUFFER_SIZE;
			tokens = realloc(tokens, buffer_size * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\n");
	}
	tokens[position] = NULL;
	*argc = position;
	return (tokens);
}
/**
 * adebisi12 - main function
 *
 * Return: nothng
 */
int adebisi12(void)
{
	char *line = NULL;
	size_t line_size = 0;
	ssize_t chars_read;
	int argc, i;
	char **argv;

	while (1)
	{
		printf("MyShell> ");
		chars_read = read_line(line, line_size);

		if (chars_read == -1)
		{
			fprintf(stderr, "Buffer size is zero\n");
			exit(EXIT_FAILURE);
		}

		if (chars_read == 0)
		{
			break;
		}

		argv = split_line(line, &argc);

		if (argc > 0)
		{
			for (i = 0; i < argc; i++)
			{
				printf("Argument %d: %s\n", i, argv[i]);
				free(argv[i]);
			}
		}
		free(argv);
	}
	free(line);
	return (0);
}
