#include "builtin_functions.h"

/**
 * _err_ - function that prints an error on failure to cd
 * @info: represents the shell info
 * @dir: the cd directory
 */
void _err_(info_t *shellInfo, char *dir)
{
	char *err;
	*err = strjoin(NULL, " ", "can't cd to", dir);

	perrorl_default(*shellInfo->argv, error, shellInfo->lineno, *shellInfo->tokens, NULL);
	shellInfo->status = 2;

	free(err);
}


/**
 * _success -function that updates the environment on cd success
 * @shellInfo: the shell info
 */
void _success(info_t *shellInfo)
{
	char **tokens;
	char *tks_setenv[] = {"setenv", NULL, NULL, NULL};

	**tokens = shellInfo->tokens;

	shellInfo->tokens = tks_setenv;

	tks_setenv[1] = "OLDPWD";
	tks_setenv[2] = shellInfo->cwd;

	_setenv_(shellInfo);

	free(shellInfo->cwd);
	shellInfo->cwd = getcwd(NULL, 0);

	tks_setenv[1] = "PWD";
	tks_setenv[2] = shellInfo->cwd;

	_setenv_(shellInfo);

	shellInfo->tokens = tokens;

	shellInfo->status = EXIT_SUCCESS;
}


/**
 * _cd_ - function that changes the directory
 * @shellInfo: the argument passed
 *
 * Return: an int
 */
int _cd_(info_t *shellInfo)
{
	char *dir = NULL;
	char **args = shellInfo->tks + 1;

	shellInfo->status = EXIT_SUCCESS;
	if (*args)
	{
		if (!_strcmp(*args, "-"))
		{
			dir = get_dict_val(shellInfo->env, "OLDPWD");
			if (!dir)
				dir = shellInfo->cwd;

			shellInfo->status = chdir(dir);
			if (!shellInfo->status)
			{
				write(STDOUT_FILENO, dir, _strlen(dir));
				write(STDOUT_FILENO, "\n", 1);
			}
		}
		else
		{
			dir = *args;
			shellInfo->status = chdir(dir);
		}
	}
	else
	{
		dir = get_dict_val(shellInfo->env, "HOME");
		if (dir)
			shellInfo->status = chdir(dir);
	}
	if (shellInfo->status != -1)
		_success(shellInfo);
	else
		_err_(shellInfo, dir);

	return (shellInfo->status);
}

