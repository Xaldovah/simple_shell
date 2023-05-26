#include "shell.h"

/**
 * _alpha - This func checks for alplabets
 * @a: The char to check
 *
 * Return: Return 1 if it's true 0 if false
 */

int _alpha(int a)
{
	if (((a >= 97) && (a <= 122)) || ((a >= 65) && (a <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _cd - This function changes directories
 * @command: ...
 * @last: ...
 *
 * Return: 0 if it succeeds 1 if it fails
 */

int _cd(char **command, __attribute__((unused))int last)
{
	int woth = -1;
	char cwd[PATH_MAX];

	if (command[1] == NULL)
		woth = chdir(getenv("HOME"));
	else if (_strcmp(command[1], "-") == 0)
	{
		woth = chdir(getenv("OLDPWD"));
	}
	else
		woth = chdir(command[1]);

	if (woth == -1)
	{
		perror("shell");
		return (-1);
	}
	else if (woth != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * echo_exec - This func excutes the echo
 * @command: of last command
 * @status: ...
 *
 * Return: ...
 */

int echo_exec(char **command, int status)
{
	char *pass;
	unsigned int  pid = getppid();

	if (_strncmp(command[1], "$?", 2) == 0)
	{
		_putchr(status);
		_puts("\n");
	}
	else if (_strncmp(command[1], "$$", 2) == 0)
	{
		un_putchar(pid);
		_puts("\n");

	}
	else if (_strncmp(command[1], "$PATH", 5) == 0)
	{
		pass = custom_getenv("PATH");
		_puts(pass);
		_puts("\n");
		free(pass);

	}
	else
	{
		return (_echo(command));
	}

	return (1);
}
