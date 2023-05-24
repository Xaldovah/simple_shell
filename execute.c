#include "shell.h"

/**
  * concatenate_path - Concatenate both names
  * @dir_path: ...
  * @file_name: ...
  *
  * Return: Concatenated names
  */

char *concatenate_path(char *dir_path, char *file_name)
{
	int file_name_len = 0, dir_path_len = 0, novo_size = 0;

	file_name_len = _strlen(file_name);
	dir_path_len = _strlen(dir_path);
	novo_size = sizeof(char) * (dir_path_len + file_name_len + 2);
	dir_path = _realloc(dir_path, (dir_path_len + 1), novo_size);

	if (!dir_path)
	{
	return (NULL);
	}

	_strcat(dir_path, "/");
	_strcat(dir_path, file_name);

	return (dir_path);
}

/**
  * lookup_path - ...
  * @command_name: ...
  *
  * Return: Path name or NULL
  */
char *lookup_path(char *command_name)
{
	char *environ_path = NULL;
	char **path_tokens = NULL;
	int a = 0, num_delims = 0;
	struct stat st;

	if (command_name)
	{
		if (stat(command_name, &st) != 0 && command_name[0] != '/')
		{
			environ_path = custom_getenv("PATH");
			num_delims = count_chars(environ_path, ":") + 1;
			path_tokens = custom_tokenize(environ_path, ":", num_delims);

			while (path_tokens[a])
			{
				path_tokens[a] = concatenate_path(path_tokens[a], command_name);
				if (stat(path_tokens[a], &st) == 0)
				{
					free(command_name);
					command_name = _strdup(path_tokens[a]);
					free(path_tokens);
					return (command_name);
				}
				a++;
			}
			free(path_tokens);
		}
		if (stat(command_name, &st) == 0)
			return (command_name);
	}
	free(command_name);
	return (NULL);
}

/**
 * execute_cmd - ...
 * @command_name: ...
 * @arguments: ...
 *
 * Return: ...
 */

int execute_cmd(char *command_name, char **arguments)
{
	pid_t child_pid;
	int status;

	switch (child_pid = fork())
	{
	case -1:
		perror("fork");
		return (-1);
	case 0:
		execve(command_name, arguments, environ);
		perror("execve"); /* Handle execve error */
		exit(EXIT_FAILURE); /* Terminate child process on error */
	default:
		do {
		waitpid(child_pid, &status, WUNTRACED);
		} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}

	return (0);
}
