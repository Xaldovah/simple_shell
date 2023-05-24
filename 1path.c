#include "shell.h"

/**
 * check_path - This funct checks if cmd functions
 * @cmd: cmd to check
 *
 * Return: path
 */
char *check_path(char *cmd)
{
	char *path = getenv("PATH");
	char *path_copy, *path_token, *file_path;
	int cmd_len, dir_len;
	struct stat buffer;

	if (!path)
		return (NULL);
	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);
	cmd_len = _strlen(cmd);
	path_token = strtok(path_copy, ":");
	while (path_token)
	{
		dir_len = _strlen(path_token);
		file_path = malloc(cmd_len + dir_len + 2);
		if (!file_path)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(file_path, path_token);
		_strcat(file_path, "/");
		_strcat(file_path, cmd);
		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		free(file_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	if (stat(cmd, &buffer) == 0)
		return (cmd);
	return (NULL);
}
