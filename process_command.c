#include "shell.h"

/**
 * process_command - Processes commands from the input line
 * @line: Input line containing one or more commands
 *
 * Return: 0 on success, or error code on failure
 */

int process_command(char *line)
{
	char *command;
	int status = 1;

	command = strtok(line, "\n");

	while (command != NULL)
	{
		while (*command == ' ' || *command == '\t')
			command++;

		if (*command != '\0')
		{
			char **args = split_line(command);

			status = execute_command(args);
			free(args);
		}
		command = strtok(NULL, "\n");
	}

	return (status);
}
