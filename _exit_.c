#include "builtin_functions.h"

/**
  * _exit_ - a function that exits from shell
  * @shellInfo: the arguments
  * Return: returns an integer
  */

int _exit_(info_t *shellInfo)
{
	char **args;
	**args = shellInfo->tokens + 1;

	if (*args)
	{
		if (_isnumber(*args))
		{
			shellInfo->status = atoi(*args);
		}
		else
		{
			perrorl_default(*shellInfo->argv, shellInfo->lineno, *args,
					*shellInfo->tokens, "Illegal number", NULL);
			shellInfo->status = 2;
			return (shellInfo->status);
		}
	}
	if (shellInfo->file)
	{
		close(shellInfo->fileno);
	}
	exit(shellInfo->status);
}
