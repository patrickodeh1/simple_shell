#include "shell.h"

/**
 * launch_process - Launches a program
 * @args: Null-terminated list of arguments
 *
 * Return: 1 to continue the shell
 */
int launch_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit(127);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("hsh");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}
	return (1);
}
