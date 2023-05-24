#include "shell.h"

/**
 * _putchar - ...
 * @i: Char to print
 *
 * Return: 1 on success and -1 on failure
 */
int _putchar(char i)
{
	return (write(1, &i, 1));
}

/**
  * _puts - Prints str
  * @s: String
  *
  * Return: Void
  */
void _puts(char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}

	_putchar('\n');
}

/**
  * _strncmp - ...
  * @str1: ...
  * @str2: ...
  * @limit: ...
  *
  * Return: ...
  */
int _strncmp(const char *str1, const char *str2, size_t limit)
{
	unsigned int loc = 0;
	int variance = 0;

	while (loc < limit)
	{
		if (str1[loc] == str2[loc])
		{
			loc++;
			continue;
		}
		else
		{
			variance = str1[loc] - str2[loc];
			break;
		}

		loc++;
	}

	return (variance);
}

/**
  * _realloc - ...
  * @pointer: Previously allocated ptr
  * @prev_size: ...
  * @new_size: ...
  *
  * Return: A new ptr
  */
void *_realloc(void *pointer, unsigned int prev_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int a;

	if (new_size == prev_size)
		return (pointer);

	if (pointer == NULL)
	{
		new_ptr = malloc(new_size);

		if (new_ptr == NULL)
			return (NULL);

		return (new_ptr);
	}
	else
	{
		if (new_size == 0)
		{
			free(pointer);
			return (NULL);
		}
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	for (a = 0; a < prev_size && a < new_size; a++)
	{
		new_ptr[a] = ((char *) pointer)[a];
	}

	free(pointer);
	return (new_ptr);
}

/**
  * _strdup - ...
  * @s: ...
  *
  * Return: ...
  */
char *_strdup(char *s)
{
	int i = 0, length = 1;
	char *dup_s;

	if (s == NULL)
	{
		return (NULL);
	}
	length = _strlen(s);
	dup_s = malloc((sizeof(char) * length) + 1);
	if (dup_s == NULL)
	{
		return (NULL);
	}
	while (i < length)
	{
		dup_s[i] = s[i];
		i++;
	}

	dup_s[i] = '\0';
	return (dup_s);
}
