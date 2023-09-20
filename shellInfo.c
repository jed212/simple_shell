#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "shellInfo.h"

/**
 * info_init - function that initializes the shell info
 * @argc: argument count
 * @argv: argument values
 * Return: returns a pointer to the shell info
 */
info_t *info_init(int argc, char **argv)
{
	static info_t shellInfo;
	char *error = NULL;

	shellInfo.argc = argc;
	shellInfo.argv = argv;
	shellInfo.fileno = STDIN_FILENO;

	if (argc > 1)
	{
		shellInfo.file = argv[1];
		shellInfo.fileno = open(ShellInfo.file, O_RDONLY);
		if (shellInfo.fileno == -1)
		{
			error = strjoin(NULL, " ", "Can't open", shellInfo.file);
			perrorl_default(*argv, shellInfo.lineno, error, NULL);
			free(error);
			shellInfo.status = 127;
			exit(free_info(&shellInfo));
		}
	}
	shellInfo.interactive = isatty(shellInfo.fileno);
	shellInfo.pid = getpid();
	shellInfo.cwd = getcwd(NULL, 0);
	shellInfo.env = env_to_dict(environ);
	return (&shellInfo);
}


/**
 * free_info - a function that nullifies and frees
 * dynamically allocated info
 * @shellInfo: a pointer to the info
 * Return: returns the current exit status
 */
int free_info(info_t *shellInfo)
{
	free(shellInfo->line);
	shellInfo->line = _getline(-1);
	free_tokens(&shellInfo->tokens);
	free(shellInfo->exe);
	shellInfo->exe = NULL;
	free(shellInfo->cwd);
	shellInfo->cwd = NULL;
	free_dict(&shellInfo->env);
	free_dict(&shellInfo->aliases);
	free_list(&shellInfo->path);
	free_cmdlist(&shellInfo->commands);
	return (shellInfo->status);
}
