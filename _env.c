#include "shell.h"

/**
 * prt_environ - This function prints the current env.
 *
 * Return: Does not return.
 */
void prt_environ(void)
{
	int a = 0, b = 0;

	while (environ[a])
	{
		b = 0;
		while (environ[a][b])
		{
			write(STDOUT_FILENO, &environ[a][b], 1);
			b++;
		}
		if (b != 0)
			write(STDOUT_FILENO, "\n", 1);
		a++;
	}
}
