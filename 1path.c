#include "shell.h"

/**
 * _executable - determines if file is an exec cmd
 * @paper: info struct
 * @pass: path to file
 *
 * Return: 1 if true or 0 if false
 */
int _executable(info_t *paper, char *pass)
{
	struct stat st;

	(void)paper;
	if (!pass || stat(pass, &st))
	{
		return (0);
	}
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * _chars - This function is responsible for duplicating characters
 * @passtr: ...
 * @begin: beginning index
 * @end: ending index
 *
 * Return: pointer to a new buffer expected
 */
char *_chars(char *passtr, int begin, int end)
{
	static char buffer[1024];
	int a = 0, b = 0;

	for (b = 0, a = begin; a < end; a++)
	{
		if (passtr[a] != ':')
		{
			buffer[b++] = passtr[a];
		}
	}
	buffer[b] = 0;
	return (buffer);
}

/**
 * _path - Func finds command PATH str
 * @paper: info struct
 * @passtr: PATH str
 * @command: command to find
 *
 * Return: The full path of the command or NULL
 */
char *_path(info_t *paper, char *passtr, char *command)
{
	int a = 0, current_loc = 0;
	char *pass;

	if (!passtr)
	{
		return (NULL);
	}
	if ((_strlen(command) > 2) && _check(command, "./"))
	{
		if (_executable(paper, command))
		{
			return (command);
		}
	}
	while (1)
	{
		if (!passtr[a] || passtr[a] == ':')
		{
			pass = _chars(passtr, current_loc, a);
			if (!*pass)
			{
				_strcat(pass, command);
			}
			else
			{
				_strcat(pass, "/");
				_strcat(pass, command);
			}
			if (_executable(paper, pass))
			{
				return (pass);
			}
			if (!passtr[a])
				break;
			current_loc = a;
		}
		a++;
	}
	return (NULL);
}
