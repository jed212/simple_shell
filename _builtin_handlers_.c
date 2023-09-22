#include "shell.h"

const struct bltn_cmmnd bltns[] = {
	{"env", _env_},
	{"exit", exit_builtin_},
	{NULL, NULL}
};

/**
 * _is_builtin_ - a function that confirms if a command is builtin
 * @token_arr: a command array that contains tokens
 * Return: 1 if builtin cmd 0 otherwise
 */

int _is_builtin_(char **token_arr)
{
	int bltn_index;

	if (token_arr == NULL)
		return (0);
	if (token_arr[0] == NULL)
		return (0);

	for (bltn_index = 0; bltns[bltn_index].n != NULL;
			bltn_index++)
		if (strcmp(token_arr[0], bltns[bltn_index].n) == 0)
			return (1);
	return (0);
}

/**
 * _bltn_handler_ - this function handles builtin commands
 * @token_arr: the array ontaining tokens
 *
 * Return: 1 if succesfully executed,0 otherwise
 */
int _bltn_handler_(char **token_arr)
{
	int bltn_index;

	if (token_arr == NULL)
	{
		return (0);
	}
	if (token_arr[0] == NULL)
	{
		return (0);
	}

	for (bltn_index = 0; bltns[bltn_index].n != NULL;
			bltn_index++)
	{
		if (strcmp(token_arr[0],
					bltns[bltn_index].n) == 0)
		{
			return (bltns[bltn_index].function(token_arr));
		}
	}
	return (0);
}
