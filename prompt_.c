#include "shell.h"

/**
 * display_prompt - function that displays a command line
 * prompt if running in an interactive session.
 * Description:
 * Checks if the program is running in
 * an interactive terminal session
 * and displays a simple prompt if yes
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", strlen("$ "));
}
