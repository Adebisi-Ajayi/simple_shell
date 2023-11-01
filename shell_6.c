#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * _getline - Custom getline function to read input from the user.
 *
 * Description: This function reads a line of text from the user, storing it
 * in a buffer and returning a pointer to the line. It uses a static buffer
 * to read multiple characters at once and minimize calls to the read system call.
 *
 * Return: A pointer to the line read, or NULL on error or EOF.
 */
char *_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_index;
	static int bytes_read;

	char *line = NULL;
	int line_length = 0;
	int character;

	while (1)
	{
		if (buffer_index >= bytes_read)
	{
		/* Buffer is empty or all data has been processed, read more data */
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);

		buffer_index = 0;
	}

		character = buffer[buffer_index++];
		if (character == '\n' || character == '\0')
		{
			/* End of line or null terminator found */
			if (line == NULL)
				return (NULL);
			line[line_length] = '\0';
			return (line);
		}
		else
		{
			/* Append character to the line */
			char *temp = realloc(line, line_length + 1);

			if (temp == NULL)
			{
				free(line);
				return (NULL);
			}
			line = temp;
			line[line_length++] = character;
		}
	}
}
/**
 * adebisi - the main function
 * @input: the value to input
 * Return: nothing
 */

int adebisi(char *input)
{
	/*char *input;*/

	while (1)
	{
		input = _getline();
		if (input == NULL)
			break;

		printf("You entered: %s\n", input);
		free(input);
	}
	return (0);
}
