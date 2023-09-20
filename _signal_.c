#include "main.h"
/**
 *sig_int - reprompts
 *@signal: signal passed
 */
void sig_int(int signal)
{
	fflush(STDIN_FILENO);
	write(STDERR_FILENO, "\n$ ", 3);
}
