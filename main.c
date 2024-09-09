#include "shell.h"

int process_command(char *command);
void handle_input(void);

/**
 * main - Entry point of the shell program
 *
 * Return: 0 on success, or error code on failure
 */

int main(void)
{
	handle_input();
	return (0);
}

/**
 * handle_input - Entry point of the shell program
 */

void handle_input(void)
{
	char *line;
	int status = 1;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		line = read_line();
		if (!line)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		status = process_command(line);
		free(line);
	}
}
