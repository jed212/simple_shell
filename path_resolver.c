#include "shell.h"

/**
 * valid_path_ - function that checks if a file
 * contains prefixes
 * @file_name: the filename to check
 *
 * Return: 1 if file is  executable, 0 otherwise
 */
int valid_path_(char *file_name)
{
	size_t len;

	len = strlen(file_name);

	if (len >= strlen("../"))
	{
		if (strncmp(file_name, "../", strlen("../")) == 0)
		{
			return (1);
		}
	}
	if (len >= strlen("/"))
	{
		if (strncmp(file_name, "/", strlen("/")) == 0)
		{
			return (1);
		}
	}
	if (len >= strlen("./"))
	{
		if (strncmp(file_name, "./", strlen("./")) == 0)
			return (1);
	}
	return (0);
}

/**
 * create_filepath - function that creates a full file
 * path by combining a filename and dir
 * @file_path: a pointer to store the contsructed
 * file path
 * @token_arr: represents an array of
 * directory paths
 * @file_name: file name to add to the dir path
 * @token_indx: index of the dir path in the array
 *
 * Return: void
 */
void create_filepath(char **file_path, char **token_arr,
		char *file_name, int token_indx)
{
	malloc_char_(file_path,
			(strlen(token_arr[token_indx]) + strlen(file_name) + 2),
			"_which Error: malloc failed for file_path");
	strcpy(*file_path, token_arr[token_indx]);
	strcat(*file_path, "/");
	strcat(*file_path, file_name);
	strcat(*file_path, "\0");
}

/**
 * _which_ - function that finds the full path of
 * an executable file in the system
 * @file_name: the command or file name to search for
 * Return: returns the full path to the exec,
 * NULL if exec not found or filename invalid
 */
char *_which_(char *file_name)
{
	struct stat sb;
	char *delimiter, *path_var, *file_path, **token_arr;
	int  token_indx, path_exist;

	delimiter = ":";
	path_var = _getenv_("PATH");
	if (path_var != NULL)
	{
		token_arr = _array_maker_(path_var, delimiter);
		if (token_arr != NULL)
		{
			for (token_indx = 0; token_arr[token_indx];
					token_indx++)
			{
				create_filepath(&file_path, token_arr, file_name, token_indx);
				path_exist = stat(file_path, &sb);
				if (path_exist == 0)
				{
					_free_which(&path_var, token_arr);
					return (file_path);
				}
				free(file_path);
			}
			_free_which(&path_var, token_arr);
		}
		else
			free(path_var);
	}
	path_exist = stat(file_name, &sb);

	if (path_exist == 0 && valid_path_(file_name))
		return (strdup(file_name));
	return (NULL);
}
