#include "builtin_functions.h"

/**
 * _setenv_ - a function that sets the env variables
 * @shellInfo: the passed argument
 * Return: returns the status
 */
int _setenv_(info_t *shellInfo)
{
	env_t *var;
	char **args;
	char *val = "";

	**args = shellInfo->tokens + 1;

	if (args[0] == NULL)
	{
		_env_(shellInfo);
		return (shellInfo->status);
	}
	if (args[2])
	{
		perrorl("Too many arguments.", *shellInfo->tokens, NULL);
		shellInfo->status = EXIT_FAILURE;
		return (shellInfo->status);
	}
	if (args[1])
	{
		val = args[1];
	}
	var = get_dict_node(shellInfo->env, args[0]);

	if (var)
	{
		free(var->val);
		var->val = _strdup(val);
	}
	else
	{
		add_dict_node_end(&shellInfo->env, args[0], val);
	}
	shellInfo->status = EXIT_SUCCESS;
	return (shellInfo->status);
}
