#include "shell.h"

/**
 * builtin - This function executes built in cmds
 * @tokens: An array of strings containing the tokens
 * @ln: A string containing the user input
 *
 * Return: 0
 */
int builtin(char **tokens, char *ln)
{
	int a = 0, b;
	char *listcommands[] = { "exit", "cd", "env", "echo", NULL };

	while (listcommands[a])
	{
		if (strcmp(tokens[0], listcommands[a]) == 0)
		{
			switch (a)
			{
				case 0:
					res_handle_exit(tokens, ln);
					break;
				case 1:
					if (tokens[1] == NULL)
					{
						fprintf(stderr, "cd: no argument provided\n");
						return (1);
					}
					chdir(tokens[1]);
					return (1);
				case 2:
					prt_environ();
					return (1);
				case 3:
					b = 1;
					while (tokens[b])
					{
						write(STDOUT_FILENO, tokens[b], strlen(tokens[b]));
						write(STDOUT_FILENO, " ", 1);
						b++;
					}
					write(STDOUT_FILENO, "\n", 1);
					return (1);
				default:
					break;
			}
		}
		a++;
	}
	return (0);
}
