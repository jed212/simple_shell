#include "shell.h"

/**
 * malloc_char_ - function that allocates memory for a character a string
 *
 * @string: a reference to the pointer where the allocated str will be stored
 * @size_of_malloc: size of the memory to allocate
 * @error_msg: error message to display in failure
 *
 * Return: NULL, otherwise a pointer to allocated memory if successful
 */
char *malloc_char_(char **string, size_t size_of_malloc, char *error_msg)
{
	*string = (char *) malloc(sizeof(char) * size_of_malloc);
	if (string == NULL)
	{
		perror(error_msg);
		return (NULL);
	}
	return (*string);
}

/**
 * malloc_array_ - function that allocates memory for an array of strings
 *
 * @array: reference to the pointer where allocated arr is stored
 * @size_of_malloc: size to allocate
 * @error_msg: message to display in error
 *
 * Return: NULL on failure, otherwise pointer to allocated mem
 */
char **malloc_array_(char **arr, size_t size_of_malloc, char *error_msg)
{
	arr = (char **) malloc(sizeof(char *) * size_of_malloc);
	if (!arr)
	{
		perror(error_msg);
		return (NULL);
	}
	return (arr);
}

/**
 * cpy_arr - a function that copies an array of strings
 * @dest: the destination array
 * @src: source array
 * Return: return description
 */
int cpy_arr(char **dest, char **src)
{
	size_t new_env_indx, free_indx;

	for (new_env_indx = 0; src[new_env_indx]; new_env_indx++)
	{
		dest[new_env_indx] = malloc(sizeof(char) *
				strlen(src[new_env_indx]));
		if (dest[new_env_indx] == NULL)
		{
			perror("_setenv_() Error: new_env[new_env_indx] malloc failed");
			for (free_indx = 0; free_indx < new_env_indx;
					free_indx++)
			{
				free(dest[new_env_indx]);
			}
			free(dest);
			return (-1);
		}
		strcpy(dest[new_env_indx], src[new_env_indx]);
	}
	return (0);
}

/**
 * _env_len- a function that gets the length of an env
 * Return: the length
 */
int _env_len(void)
{
	unsigned int env_len;

	for (env_len = 0; __environ[env_len]; env_len++)
		;
	return (env_len);
}

/**
 * name_exists - a function that checks if an env variable name exists
 * @n: name to check
 *
 * Return: index of variable else -1
 */
int name_exists(const char *n)
{
	int env_indx;
	int found;

	found = -1;
	for (env_indx = 0; __environ[env_indx]; env_indx++)
	{
		if (strncmp(__environ[env_indx], n, strlen(n)) == 0)
			found = env_indx;
	}
	return (found);
}
