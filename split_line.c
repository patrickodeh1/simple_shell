#include "shell.h"

/**
 * split_line - Splits a line into tokens
 * @line: The line to be split
 *
 * Return: Array of tokens
 */
char **split_line(char *line)
{
	int bufsize = MAX_TOKENS, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \n\t");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += MAX_TOKENS;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("allocation error");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOKEN_DELIMITERS);
	}
	tokens[position] = NULL;
	return (tokens);
}
