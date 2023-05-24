#include "shell.h"

/**
  * rem_newline_char - ...
  * @str: ...
  *
  * Return: string sin \n
  */
char *rem_newline_char(char *str)
{
	int a = 0;

	while (str[a])
	{
		if (str[a] == '\n')
			str[a] = '\0';
		a++;
	}
	return (str);
}
