#include "shell.h"

/**
  * custom_signal_handler - Responsible for the signals in the main
  * @signal_iden: Signal to handle (Identifier).
  *
  * Description: This function handles the SIGINT signal, which is triggered
  * when the user types CTRL+C on the keyboard. It writes a new line followed
  * by the shell prompt.
  *
  * Return: Nothing to returns
  */
void custom_signal_handler(int signal_iden)
{
	if (signal_iden == SIGINT)
	{
		write(STDOUT_FILENO, "\nshell$ ", 9);
		fflush(stdout);
	}
}
