#include "shell.h"

/**
 * print_env_ - a function that prints the env variable
 * Return: 0 always
 */
int print_env_(void)
{
	unsigned int env_idx;

	for (env_idx = 0; __environ[env_idx]; env_idx++)
	{
		printf("%s\n", __environ[env_idx]);
	}
	return (0);
}
