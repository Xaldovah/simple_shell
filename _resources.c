#include "shell.h"

/**
  * _strcat - ...
  * @destination: ...
  * @source: ...
  *
  * Return: ...
  */
char *_strcat(char *destination, char *source)
{
	int dest_length = 0, a = 0;

	while (destination[dest_length])
		dest_length++;

	for (a = 0; source[a] != '\0'; a++)
	{
		destination[dest_length] = source[a];
		dest_length++;
	}

	destination[dest_length] = '\0';
	return (destination);
}

/**
  * _strlen - ...
  * @str: ...
  *
  * Return: ...
  */
int _strlen(const char *str)
{
	int a = 0;

	while (str[a])
		a++;

	return (a);
}

/**
  * _strcmp - ...
  * @s1: ...
  * @s2: ...
  *
  * Return: ...
  */
int _strcmp(char *s1, char *s2)
{
	int length_s1 = 0, length_s2 = 0, loc = 0, variance = 0, limit = 0;

	length_s1 = _strlen(s1);
	length_s2 = _strlen(s2);

	if (length_s1 <= length_s2)
		limit = length_s1;
	else
		limit = length_s2;

	while (loc <= limit)
	{
		if (s1[loc] == s2[loc])
		{
			loc++;
			continue;
		}
		else
		{
			variance = s1[loc] - s2[loc];
			break;
		}
		loc++;
	}
	return (variance);
}
/**
  * _atoi - ...
  * @str: ...
  *
  * Return: ...
  */
int _atoi(char *str)
{
	int sec = 1, digit_count = 0, a = 0;
	unsigned int result = 0;

	while (str[a])
	{
		if (str[a] == '-')
			sec = -1;

		while (str[a] >= '0' && str[a] <= '9')
		{
			digit_count = 1;
			result = (result * 10) + (str[a] - '0');
			a++;
		}

		if (digit_count == 1)
			break;

		a++;
	}

	result *= sec;
	return (result);
}

/**
 * _check - checks if pinch starts with memstack
 * @memstack: string to search
 * @pinch: the substring to find
 *
 * Return: address of next char of memstack or NULL
 */
char *_check(const char *memstack, const char *pinch)
{
	while (*pinch)
	{
		if (*pinch++ != *memstack++)
		{
			return (NULL);
		}
	}
	return ((char *)memstack);
}
