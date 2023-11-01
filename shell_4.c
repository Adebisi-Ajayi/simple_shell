#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
/**
 * shell_4 - Entry point of the shell program.
 *
 * Description: This function initializes a simple shell and enters a loop
 * to continuously prompt the user for input. The user can exit the shell
 * by typing "exit."
 *
 * Return: 0 (successful execution).
 */
int shell_4(void)
{
	char input[100];

	while (1)
	{
		printf("MyShell> ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			printf("Exiting the shell...\n");
			break; /* Exit the loop and, subsequently, the shell*/
		}
		else
		{
			printf("You entered: %s\n", input);
		}
	}
	return (0);
}
