#include "shell.h"

/**
 * main - Entry point
 *
 * Return: 0.
 */

int main(void)
{
	char *input_lne = NULL, **tokens = NULL;
	int word_len = 0, exec_flag = 0;
	size_t ln_sze = 0;
	ssize_t line_length = 0;

	while (1)
	{
		signal(SIGINT, custom_signal_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "shell$ ", 7);
		line_length = getline(&input_lne, &ln_sze, stdin);
		if (line_length < 0)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		word_len = count_words(input_lne);
		if (input_lne[0] != '\n' && word_len > 0)
		{
			tokens = custom_tokenize(input_lne, " \t", word_len);
			exec_flag = builtin(tokens, input_lne);
			if (!exec_flag)
			{
				tokens[0] = lookup_path(tokens[0]);
				if (tokens[0] && access(tokens[0], X_OK) == 0)
				{
					execute_cmd(tokens[0], tokens);
				}
				else
				{
					perror("./shell");
				}
			}
			free(tokens);
		}
	}
	free(input_lne);
	return (0);
}
