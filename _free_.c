#include "shell.h"

/**
 * _free_main - function that frees memory allocated
 * for an arr of tokens and an iput
 * @token_arr: the array of tokens
 * @input: input string to be freed
 *
 * Return: void
 */
void _free_main(char **token_arr, char *input)
{
	int idx;

	for (idx = 0; token_arr[idx]; idx++)
		free(token_arr[idx]);
	free(token_arr);
	free(input);
}

/**
 * _free_which - a function that frees memory allocated
 * for an arr of tokens and path var
 * @path_var: a pointer to the path variable to be freed
 * @token_arr: an arr of tokes to be freed
 * Return: void
 */
void _free_which(char **path_var, char **token_arr)
{
	int indx;

	if (token_arr != NULL)
	{
		for (indx = 0; token_arr[indx]; indx++)
		{
			if (token_arr[indx] != NULL)
			{
				free(token_arr[indx]);
			}
		}
		free(token_arr);
	}
	if (*path_var != NULL)
		free(*path_var);
}
