# Simple Shell

## Description

**Simple Shell** is a custom UNIX command-line interpreter built in C. It mimics the functionality of `/bin/sh`, handling commands in both interactive and non-interactive modes. The shell is designed to support a range of basic features and built-in commands while adhering to strict memory management and coding standards.

## Features

- Displays a prompt and executes user commands.
- Handles commands with and without arguments.
- Supports basic command execution including commands in `$PATH`.
- Built-in commands include `exit` and `env`.
- Error handling similar to `/bin/sh`.

## Compilation

Compile the shell using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

Interactive mode:

```bash
$ ./hsh
($) /bin/ls
file1 file2 file3
($) exit
```

Non-interactive mode:

```bash
$ echo "/bin/ls" | ./hsh
file1 file2 file3
```

## Requirements

- Ubuntu 20.04 LTS
- GCC with options: -Wall -Werror -Wextra -pedantic -std=gnu89
- Code style follows Betty standards.
- System Calls and Functions
access, chdir, close, execve, fork, free, malloc, read, write, and more.

## Author

Patrick Odeh