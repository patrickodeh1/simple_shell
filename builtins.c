#include "shell.h"
#include <unistd.h> /* for STDOUT_FILENO */
#include <string.h> /* for strlen */

/**
 * shell_env - Prints the environment variables
 * @args: List of arguments (not used here)
 *
 * Return: Always 1 (to continue the shell)
 */
int shell_env(char **args)
{
	char **env = environ; /* Access environ directly */
	int i = 0;

	(void)args;
	while (env[i])
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}

/**
 * shell_exit - Exits the shell
 * @args: List of arguments
 *
 * Return: Always 0 (to terminate the shell)
 */
int shell_exit(char **args)
{
	if (args != NULL)
		free(args);
	exit(0);
}
