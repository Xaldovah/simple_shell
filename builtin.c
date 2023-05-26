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
	char *listcommands[] = { "exit", "cd", "env", NULL };

	while (listcommands[a])
	{
		if (_strcmp(tokens[0], listcommands[a]) == 0)
		{
			switch (a)
			{
				case 0:
					execute_exit(tokens, ln);
					break;
				case 1:
					chdir(tokens[1]);
					return (1);
				case 2:
					execute_env();
					return (1);
				case 3:
					execute_setenv(tokens);
					return (1);
				case 4:
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
		status = _atoi(tokens[1]);

	free_tokens(tokens);
	free(ln);
	exit(status);
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
