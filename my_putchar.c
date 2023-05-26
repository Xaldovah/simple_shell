#include "shell.h"

/**
 * un_putchar -This func prints an unsigned int putchar
 * @i: ...
 *
 * Return: void
 */

void un_putchar(unsigned int i)
{
	unsigned int s = i;

	if ((s / 10) > 0)
		un_putchar(s / 10);

	_putchar(s % 10 + '0');
}

/**
 * _putchr - This func prints a putchar (number)
 * @i: ...
 *
 * Return: void
 */

void _putchr(int i)
{
	unsigned int s = i;

	if (i < 0)
	{
		_putchar('-');
		s = -s;
	}
	if ((s / 10) > 0)
		un_putchar(s / 10);

	_putchar(s % 10 + '0');
}

/**
 * _echo - This func prints the excuted like a normal echo command
 * @command: ...
 *
 * Return: 0 if it succeeds or -1 if it fails
 */

int _echo(char **command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", command, environ) < 0)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
