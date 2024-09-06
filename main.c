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

/**
 * process_command - Entry point of the shell program
 * @line: char
 * Return: 0 on success, or error code on failure
 */

int process_command(char *line)
{
	char *command = strtok(line, "\n");
	char **args;
	int status = 1;

	while (command != NULL)
	{
		while (*command == ' ' || *command == '\t')
			command++;
		if (*command == '\0')
		{
			command = strtok(NULL, "\n");
			continue;
		}

		args = split_line(command);
		if (!args || !args[0])
		{
			free(args);
			command = strtok(NULL, "\n");
			continue;
		}

		status = execute_command(args);
		free(args);
		command = strtok(NULL, "\n");
	}
	return (status);
}
