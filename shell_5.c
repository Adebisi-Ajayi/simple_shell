#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"
/**
 * shell_5 - Entry point of the simple shell program.
 *
 * Description: This function initializes a simple shell and enters a loop
 * to continuously prompt the user for input. The user can enter "env" to
 * display the current environment variables or "exit" to exit the shell.
 *
 * Return: 0 (successful execution).
 */
int shell_5(void)
{
	char *env_var, **environ;
	char input[100];

	while (1)
	{
		printf("MyShell> ");
		fgets(input, sizeof(input), stdin);
	       /* Remove trailing newline character */
		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			printf("Exiting the shell...\n");
			break; /* Exit the loop and, subsequently, the shell */
		}
		else if (strcmp(input, "env") == 0)
		{
			/* Print the current environment variables */
			env_var = * environ; /* Pointer to the environment variables */

			while (env_var != NULL)
			{
				printf("%s\n", env_var);
				env_var = *(environ++); /* Move to the next environment variable */
			}
		}
		else
		{
			/* Handle other commands or operations here */
			printf("You entered: %s\n", input);
		}
	}
	return (0);
}
