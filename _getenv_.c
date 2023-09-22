#include "shell.h"

/**
 * _getenv_ - gets the value of the environment variable
 * @n: name of the variable to retrieve
 * Return: returns a pointer to the val of the environment,
 * variable, otherwise NULL
 */
char *_getenv_(const char *n)
{
	unsigned int envar_len;
	unsigned int env_indx;
	char *env_var;
	char *cpy_env_var;

	for (env_indx = 0; __environ[env_indx]; env_indx++)
	{
		if (strncmp(__environ[env_indx], n, strlen(n)) == 0)
		{
			envar_len = strlen(__environ[env_indx]) - (strlen(n));
			env_var = malloc(sizeof(char) * envar_len);
			if (!env_var)
			{
				perror("_getenv() Error: env_var malloc failed");
				return (NULL);
			}
			malloc_char_(&cpy_env_var, strlen(__environ[env_indx]) + 1,
					"_getenv_() malloc error");
			strcpy(cpy_env_var, __environ[env_indx]);
			strncpy(env_var, cpy_env_var += (strlen(n) + 1), envar_len);
			free(cpy_env_var -= (strlen(n) + 1));
			return (env_var);
		}
	}
	return (NULL);
}
