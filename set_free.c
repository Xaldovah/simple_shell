#include "shell.h"

/**
  * frees_get_env - This function is responsible to free get env
  * @environ_path: env var to frees
  *
  * Return: Nothing
  */
void frees_get_env(char *environ_path)
{
	int a;

	for (a = 4; a >= 0; a--)
		environ_path--;

	free(environ_path);
}

/**
  * frees_tokens - This function is responsible to free tokens
  * @tokens: token var to frees
  *
  * Return: Nothing to returns
  */
void frees_tokens(char **tokens)
{
	char **temp = tokens;

	if (tokens)
	{
		while (*tokens)
			free(*tokens++);

		free(temp);
	}
}
