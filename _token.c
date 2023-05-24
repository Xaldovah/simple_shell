#include "shell.h"

/**
  * custom_tokenize - ...
  * @str: ...
  * @delimiter: ...
  * @count:
  *
  * Return: array of args or NULL
  */
char **custom_tokenize(char *str, char *delimiter, int count)
{
	char **token_array = NULL, *current_token = NULL, *temp_str = NULL;
	int a = 0;

	token_array = malloc(sizeof(char *) * (count + 1));
	if (!token_array)
	{
		return (NULL);
	}
	str = rem_newline_char(str);
	temp_str = _strdup(str);
	current_token = strtok(temp_str, delimiter);

	while (current_token)
	{
		token_array[a] = _strdup(current_token);
		current_token = strtok(NULL, delimiter);
		a++;
	}
	token_array[a] = NULL;
	free(temp_str);
	return (token_array);
}
