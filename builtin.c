#include "shell.h"

/**
 * builtin - Executes built-in commands
 * @tokens: Array of strings containing the tokens
 * @ln: String containing the user input
 * Return: 1 if built-in command executed, 0 otherwise
 */
int builtin(char **tokens, char *ln)
{
	int a = 0;
	char *listcommands[] = { "exit", "cd", "env", "echo", NULL };

	while (listcommands[a])
	{
		if (strcmp(tokens[0], listcommands[a]) == 0)
		{
			switch (a)
			{
				case 0:
					execute_exit(tokens, ln);
					break;
				case 1:
					execute_cd(tokens);
					return (1);
				case 2:
					execute_env();
					return (1);
				case 3:
					execute_echo(tokens);
					return (1);
				case 4:
					execute_setenv(tokens);
					return (1);
				case 5:
					execute_unsetenv(tokens);
					return (1);
				default:
					break;
			}
		}
		a++;
	}
	return (0);
}

/**
 * execute_exit - Executes the exit command
 * @tokens: Array of strings containing the tokens
 * @ln: String containing the user input
 */
void execute_exit(char **tokens, char *ln)
{
	int status = 0;

	if (tokens[1] != NULL)
		status = atoi(tokens[1]);

	free_tokens(tokens);
	free(ln);
	exit(status);
}

/**
 * execute_cd - Executes the cd command
 * @tokens: Array of strings containing the tokens
 */
void execute_cd(char **tokens)
{
	const char *dir;
	char cwd[1024];

	if (tokens[1] == NULL || _strcmp(tokens[1], "-") == 0)
	{
		dir = tokens[1] == NULL ? custom_getenv("HOME") : custom_getenv("OLDPWD");
		if (dir == NULL)
		{
			_puts(tokens[1] == NULL ? "cd: HOME Failed" : "cd: OLDPWDFailed");
			return;
		}
		if (chdir(dir) != 0)
		{
			_puts("cd: failed to change directory");
			return;
		}
	}
	else
	{
		if (chdir(tokens[1]) != 0)
		{
			_puts("cd: failed to change directory");
			return;
		}
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("PWD", cwd, 1);
		setenv("OLDPWD", custom_getenv("PWD"), 1);
	}
	else
	{
		_puts("cd: failed to get current directory");
	}
	free_tokens(tokens);
}

/**
 * execute_env - Executes the env command
 *
 * Return: None
 */
void execute_env(void)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}

/**
 * execute_echo - Executes the echo command
 * @tokens: Array of strings containing the tokens
 *
 * Return: None.
 */
void execute_echo(char **tokens)
{
	int i = 1;

	while (tokens[i])
	{
		_puts(tokens[i]);

		if (tokens[i + 1] != NULL)
		{
			_putchar(' ');
		}
		i++;
	}
	_putchar('\n');
	free_tokens(tokens);
}
