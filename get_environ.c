#include "shell.h"

/**
  * custom_getenv - This function gets an env var
  * @var_name: The var to find in sys env
  *
  * Description: This function searches for the environment variable with the
  * given name and returns its value. If the variable is not found,
  * it returns NULL.
  *
  * Return: The content of env var, or NULL if not found.
  */
char *custom_getenv(const char *var_name)
{
	int b = 0;
	char *environ_variable = NULL;

	while (environ[b])
	{
		if (_strncmp(var_name, environ[b], _strlen(var_name)) == 0)
		{
			environ_variable = _strdup(environ[b]);
			while (*environ_variable != '=')
				environ_variable++;

			++environ_variable;
			return (environ_variable);
		}
		b++;
	}

	return (NULL);
}
