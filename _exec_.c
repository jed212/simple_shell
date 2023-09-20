#include "builtin_functions.h"

/**
 * _exec_ - a function that replaces the running shell with a new program
 * @shellInfo: argument passed
 * Return:returns an int
 */
int __exec(info_t *shellInfo)
{
	char *exe;
	char **args;
	char **env = NULL;

	**args = shellInfo->tokens + 1;

	if (*args == NULL)
	{
		return ((shellInfo->status = EXIT_SUCCESS));
	}

	shellInfo->tokens = args;
	args = _arrdup_(args);

	if (_strchr(*args, '/') == -1)
	{
		free_list(&shellInfo->path);
		shellInfo->path = str_to_list(get_dict_val(shellInfo->env, "PATH"), ':');
		exe = search_path(shellInfo, shellInfo->path);
	}
	else
	{
		exe = _strdup(*args);
	}
	shellInfo->tokens -= 1;

	if (access(exe, X_OK) == 0)
	{
		env = dict_to_env(shellInfo->env);

		free_info(shellInfo);
		execve(exe, args, env);
		perrorl_default(*shellInfo->argv, shellInfo->lineno, "Not found",
				*shellInfo->tokens, *args, NULL);
		free(exe);
		free_tokens(&args);
		free_tokens(&env);
		exit(127);
	}
	perrorl_default(*shellInfo->argv, shellInfo->lineno, "Permission denied",
			*shellInfo->tokens, *args, NULL);
	free_tokens(&args);
	free_info(shellInfo);
	free(exe);

	exit(126);
}
