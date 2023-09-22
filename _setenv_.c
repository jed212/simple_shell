#include "shell.h"

/**
 * _create_env - a function that creates a new environment variable
 * @env_var: a pointer to store the created environment var
 * @envar_len: the length
 * @n: name of the env variable
 * @v: value
 *
 * Return: returns void
 */
void _create_env(char **env_var, unsigned int envar_len, const char *n,
		const char *v)
{
	*env_var = malloc_char_(env_var, envar_len,
			"_setenv_() Error: env_var malloc failed");
	envar_len = strlen(n) + strlen(v) + 2;
	*env_var = malloc_char_(env_var, envar_len,
			"_setenv_() Error: env_var malloc failed");
	strcpy(*env_var, n);
	strcat(*env_var, "=");
	strcat(*env_var, v);
	strcat(*env_var, "\0");
}

/**
 * set_env_exists - a function that checks if an environment
 * variable with that name sxists
 * @env_var: the env variable to overwrite or set
 * @envar_len: its length
 * @n: its name
 * @overwrite: flag o indicate whether to overwrite an existing env variable
 *
 * Return: 0 on success, -1 otherwise
 */
int set_env_exists(char *env_var, unsigned int envar_len, const char *n,
		int overwrite)
{
	unsigned int env_indx;

	for (env_indx = 0; __environ[env_indx]; env_indx++)
	{
		if (strncmp(__environ[env_indx], n, strlen(n)) == 0 && overwrite != 0)
		{
			free(__environ[env_indx]);
			__environ[env_indx] = malloc(sizeof(char) * envar_len);
			if (!(__environ[env_indx]))
			{
				perror("_setenv() Error: __environ[env_indx] malloc failed");
				free(env_var);
				return (-1);
			}
			strcpy(__environ[env_indx], env_var);
			free(env_var);
			return (0);
		}
	}
	return (0);
}

/**
 * doesnt_exist - function that adds a new env
 * variable if it does not already exist
 * @env_var: variable to be added
 * @envar_len: length of the variable
 * @env_len: length of enviroment
 *
 * Return: 0 on success, -1 on failure
 */
int doesnt_exist(char *env_var, unsigned int envar_len,
		unsigned int env_len)
{
	unsigned int free_indx;
	char **new_env;

	new_env = (char **) malloc(sizeof(char *) * (env_len + 2));
	if (!new_env)
	{
		perror("_setenv() Error: new_env malloc failed");
		free(env_var);
		return (-1);
	}
	cpy_arr(new_env, __environ);
	new_env[env_len] = malloc(sizeof(char) * envar_len);
	if (new_env[env_len] == NULL)
	{
		perror("_setenv_() Error: new_env[env_indx] malloc failed");
		for (free_indx = 0; free_indx < env_len;
				free_indx++)
			free(new_env[free_indx]);
		free(new_env);
		free(env_var);
		return (-1);
	}
	strcpy(new_env[env_len], env_var);
	new_env[env_len + 1] = NULL;
	free(env_var);
	__environ = new_env;
	return (0);
}

/**
 * _setenv_ - a function that sets or overwrites an env variable
 * @n: name of the env variable to set
 * @v: the value
 * @overwrite: to indicate whether to overwrite the existing var
 * Return: -1 on failure 0 on success
 */
int _setenv_(const char *n, const char *v, int overwrite)
{
	unsigned int envar_len;
	char *env_var;

	envar_len = strlen(n) + strlen(v) + 2;
	_create_env(&env_var, envar_len, n, v);
	set_env_exists(env_var, envar_len, n, overwrite);
	if (name_exists(n) != -1)
		set_env_exists(env_var, envar_len, n, overwrite);
	else
		doesnt_exist(env_var, envar_len, _env_len());
	return (0);
}
