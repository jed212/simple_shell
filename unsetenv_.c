#include "builtin_functions.h"

/**
 * _unsetenv_ - a function that unsets the env variable
 * @shellInfo: the arguments
 * Return: returns the status
 */
int _unsetenv_(info_t *shellInfo)
{
	char **args;
	**args = shellInfo->tokens + 1;

	if (*args == NULL)
	{
		perrorl("Too few arguments.", *shellInfo->tokens, NULL);
		shellInfo->status = EXIT_FAILURE;
	}
	else
	{
		while (*args)
		{
			del_dict_node(&shellInfo->env, *args);
			args++;
		}
		shellInfo->status = EXIT_SUCCESS;
	}

	return (shellInfo->status);
}
