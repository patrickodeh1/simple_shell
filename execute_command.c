#include "shell.h"

/**
 * execute_command - Executes shell built-in commands or external programs
 * @args: Null-terminated list of arguments
 *
 * Return: 1 to continue, 0 to terminate shell
 */
void execute_command(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		shell_env(args);
	}
	else
	{
		launch_process(args);
	}
}
