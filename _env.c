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
			_putchar(environ[a][b]);
			b++;
		}
		if (b != 0)
		{
			_putchar('\n');
		}
		a++;
	}
}
