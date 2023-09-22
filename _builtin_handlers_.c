#include "shell.h"

/**
 *_is_builtin_ - all it does
 **
 *Description: describe all it does
 *@token_arr: command array
 *Return: 1 if success 0 if failure
 */
int _is_builtin_(char **token_arr)
{
	int bltn_index;
	const struct bltn_cmmnd bltns[] = {
		{"env", _env_},
		{"exit", exit_builtin_},
		{NULL, NULL}
	};

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
 *_bltn_handler_ - short description
 **
 *Description: long description
 **
 *@token_arr: command array
 **
 *Return: 1 if success 0 if failure
 */
int _bltn_handler_(char **token_arr)
{
	int bltn_index;
	const struct bltn_cmmnd bltns[] = {
		{"env", _env_},
		{"exit", exit_builtin_},
		{NULL, NULL}
	};

	if (token_arr == NULL)
		return (0);
	if (token_arr[0] == NULL)
		return (0);

	for (bltn_index = 0; bltns[bltn_index].n != NULL;
			bltn_index++)
	{
		if (strcmp(token_arr[0],
					bltns[bltn_index].n) == 0)
			return (bltns[bltn_index].function(token_arr));
	}
	return (0);
}
