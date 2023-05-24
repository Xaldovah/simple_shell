#include "shell.h"

/**
 * execute_setenv - Executes the setenv command
 * @tokens: Array of strings containing the tokens
 */
void execute_setenv(char **tokens)
{
	if (tokens[1] == NULL || tokens[2] == NULL)
	{
		_puts("setenv: missing arguments");
		free_tokens(tokens);
		return;
	}
	if (setenv(tokens[1], tokens[2], 1) != 0)
	{
		_puts("setenv: failed to set environment variable");
		free_tokens(tokens);
		return;
	}
	free_tokens(tokens);
}

/**
 * execute_unsetenv - Executes the unsetenv command
 * @tokens: Array of strings containing the tokens
 */
void execute_unsetenv(char **tokens)
{
	if (tokens[1] == NULL)
	{
		_puts("unsetenv: missing argument");
		free_tokens(tokens);
		return;
	}
	if (unsetenv(tokens[1]) != 0)
	{
		_puts("unsetenv: failed to unset environment variable");
		free_tokens(tokens);
		return;
	}
	free_tokens(tokens);
}

/**
 * free_tokens - Frees the memory allocated for tokens
 * @tokens: Array of strings containing the tokens
 */
void free_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
