#include "shell.h"

/**
 * res_handle_exit - This function is responsible for handling exit
 * @res_tokens: checks arguments
 * @res_line: ...
 * Return: No return expected
 */

void res_handle_exit(char **res_tokens, char *res_line)
{
	int res_status = 0;

	if (res_tokens[1] == NULL || (!_strcmp(res_tokens[1], "0")))
	{
		free(res_tokens);
		free(res_line);
		exit(0);
	}
	res_status = atoi(res_tokens[1]);

	if (res_status != 0)
	{
		free(res_tokens);
		free(res_line);
		exit(res_status);
	}
	else
	{
		_puts("exit: prohibited: ");
		_puts(res_tokens[1]);
		_puts("\n");
		free(res_tokens);
		free(res_line);
		exit(2);
	}
}
