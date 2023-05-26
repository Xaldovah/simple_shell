#include "shell.h"

/**
 * check_char - This func checks if a char matches a character
 * @character: ...
 * @str: ...
 * Return: 1 if it succeeds, 0 if it fails
 */
unsigned int check_char(char character, const char *str)
{
	unsigned int a;

	for (a = 0; str[a] != '\0'; a++)
	{
		if (character == str[a])
			return (1);
	}
	return (0);
}

/**
 * my_strtok - This func tokenizes a string to token
 * @str: ...
 * @delimiter: ...
 * Return: Pointer to next token on success or NULL on failure
 */
char *my_strtok(char *str, const char *delimiter)
{
	static char *c, *d;
	unsigned int a;

	if (str != NULL)
		d = str;
	c = d;
	if (c == NULL)
		return (NULL);
	for (a = 0; c[a] != '\0'; a++)
	{
		if (check_char(c[a], delimiter) == 0)
			break;
	}
	if (d[a] == '\0' || d[a] == '#')
	{
		d = NULL;
		return (NULL);
	}
	c = d + a;
	d = c;
	for (a = 0; d[a] != '\0'; a++)
	{
		if (check_char(d[a], delimiter) == 1)
			break;
	}
	if (d[a] == '\0')
		d = NULL;
	else
	{
		d[a] = '\0';
		d = d + a + 1;
		if (*d == '\0')
			d = NULL;
	}
	return (c);
}
