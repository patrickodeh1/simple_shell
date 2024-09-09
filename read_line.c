#include "shell.h"

/**
 * read_line - Reads a line from stdin
 *
 * Return: Pointer to the string containing the line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	characters = getline(&line, &bufsize, stdin);
    if (characters == -1)

	{
		free(line);
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("read_line");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}