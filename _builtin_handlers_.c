#include "shell.h"

/**
 *_is_builtin_ - all it does
 **
 *Description: describe all it does
 *@array_of_tokens: command array
 *Return: 1 if success 0 if failure
 */
int _is_builtin_(char **array_of_tokens)
{
	int bltn_index;
	const struct bltn_cmmnd bltns[] = {
		{"env", _env_builtin},
		{"exit", _exit_builtin},
		{NULL, NULL}
	};

	if (array_of_tokens == NULL)					
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (bltn_index = 0; bltns[bltn_index].name != NULL;
			bltn_index++)
		if (strcmp(array_of_tokens[0],bltns[bltn_index].name) == 0)
			return (1);
	return (0);
}

/**
 *_bltn_handler_ - short description
 **
 *Description: long description
 **
 *@array_of_tokens: command array
 **
 *Return: 1 if success 0 if failure
 */
int _bltn_handler_(char **array_of_tokens)
{
	int bltn_index;
	const struct bltn_cmmnd bltns[] = {
		{"env", _env_builtin},
		{"exit", _exit_builtin},
		{NULL, NULL}
	};

	if (array_of_tokens == NULL)
		return (0);
	if (array_of_tokens[0] == NULL)
		return (0);

	for (bltn_index = 0; bltns[bltn_index].name != NULL;
			bltn_index++)
	{
		if (strcmp(array_of_tokens[0],
					bltns[bltn_index].name) == 0)
			return (bltns[bltn_index].function(array_of_tokens));
	}
	return (0);
}
