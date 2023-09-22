#include "shell.h"

/**
 * _unsetenv_ - a function that removes an environment variable by name
 * @n: the name of the environment variable to be removed/unset
 *
 * Return: 0 on success -1 on failure
 */
int _unsetenv_(const char *n)
{
	unsigned int env_indx;
	int new_env_indx, free_indx, found;
	char **new_env;

	new_env = NULL;
	env_indx = _env_length();
	found = name_exists(n);
	if (found != -1)
	{
		new_env = malloc_array_(new_env, env_indx,
				"_unsetenv_() Error: new_env malloc failed");
		for (new_env_indx = 0; __environ[new_env_indx]; new_env_indx++)
		{
			if (new_env_indx != found)
			{
				new_env[new_env_indx] = malloc(sizeof(char) *
						strlen(new_env[new_env_indx]));
				if (new_env[new_env_indx] == NULL)
				{
					perror("_unsetenv_() Error: new_env[new_env_indx] malloc failed");
					for (free_indx = 0; free_indx < new_env_indx;
							free_indx++)
						free(new_env[new_env_indx]);
					free(new_env);
					return (-1);
				}
				strcpy(new_env[new_env_indx], __environ[new_env_indx]);
			}
		}
		new_env[env_indx] = NULL;
		__environ = new_env;
	}
	return (0);
}
