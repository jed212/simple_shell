#include "shell.h"

/**
 *_sig_int_handler_ - handle signals
 *@signal: signal
 *Return: nothing
 */
void _sig_int_handler_(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		prompt();											fflush(stdout);
			
	}
}
