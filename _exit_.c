#include "shell.h"

/**
 * exit_builtin_ - a function that handles the exit builtin command in shell
 * @token_arr: an array of strings representing the command and its arguments
 * Return: 1 on success 0 on failure
 */
int exit_builtin_(char **token_arr)
{
	if (token_arr[1] != NULL)
	{
		exit(atoi(token_arr[1]));
	}
	else
	{
		return (EXIT_CODE);
	}
}
