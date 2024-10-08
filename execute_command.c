#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * execute_command - Executes shell built-in commands or external programs
 * @args: Null-terminated list of arguments
 *
 * Return: 1 to continue, 0 to terminate shell, or
 * the exit status of an external command
 */
int execute_command(char **args)
{
	int status;

	if (args[0] == NULL)
	{
		return (1);
	}

	if (getenv("PATH") == NULL || getenv("PATH")[0] == '\0')
	{
		if (args[0][0] != '/')
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			return (127);
		}
	}

	if (strcmp(args[0], "exit") == 0)
	{
		return (shell_exit(args));
	}
	else if (strcmp(args[0], "env") == 0)
	{
		return (shell_env(args));
	}
	else
	{
		status = launch_process(args);
		return (status);
	}
}
