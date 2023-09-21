#include "shell.h"

/**
 * _env_ - a function that prints the env variables
 * @token_arr: an array of strings
 *
 * Return: the number of env variables printed
 */
int _env_(__attribute((unused)) char **token_arr)
{
	int env_indx;

	for (env_indx = 0; __environ[env_indx]; env_indx++)
	{
		write(STDOUT_FILENO, __environ[env_indx],
				strlen(__environ[env_indx]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
	}
	return (env_indx);
}
