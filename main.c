#include "shell.h"
#include <stdio.h> /* for perror */
#include <stdlib.h> /* for exit */
#include <unistd.h> /* for isatty, STDOUT_FILENO */

/**
 * main - Entry point of the shell program
 *
 * Return: 0 on success, or error code on failure
 */
int main(void)
{
	char *line;
	char **args;
	int status = 1;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		line = read_line();
		if (!line)
		{
			perror("read_line");
			exit(EXIT_FAILURE);
		}

		args = split_line(line);
		if (!args)
		{
			free(line);
			continue;
		}

		execute_command(args);

		free(line);
		free(args);
	}
	return (0);
}
