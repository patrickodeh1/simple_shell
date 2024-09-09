#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_TOKENS 64
#define TOKEN_DELIMITERS " \t\r\n\a"

int execute_command(char **args);
char *read_line(void);
char **split_line(char *line);
int shell_env(char **args);
int shell_exit(char **args);
int launch_process(char **args);
extern char **environ;
int process_command(char *line);

#endif /* SHELL_H */
