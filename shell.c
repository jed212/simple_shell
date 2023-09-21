#include "shell.h"

/**
 * main - Entry point of the program
 * @ac: unused command line argument count
 * @arvs: unused command line argument
 * @envp: unused environment variable
 *
 * Return: the exit status
 */
int main(__attribute((unused)) int ac,
		__attribute((unused)) char **arvs,
		__attribute((unused)) char **envp)
{
	int status = 0;
	char *which, **token_arr;
	char *delimiter, *input;
	size_t malloc_bytes_allocated, cmd_num;

	signal(SIGINT, sigint_handler);
	input = NULL;
	malloc_bytes_allocated = cmd_num = 0;
	delimiter = " \n";
	while (1)
	{
		cmd_num++;
		_getline_(&input, &malloc_bytes_allocated, status);
		token_arr = array_maker(input, delimiter);
		if (!(*token_arr))
			status = 0;
		else
		{
			if (is_builtin(token_arr))
			{
				if (builin_handler(token_arr) == EXIT_CODE)
				{
					_free_main(token_arr, input);
					exit(status);
				}
			}
			else
			{
				which = _which_(token_arr[0]);
				if (which !=  NULL)
					status = _fork(which, token_arr);
				else
					status = error_not_found(arvs, token_arr, cmd_num);
			}
		}
		_free_main(token_arr, input);
		input = NULL;
	}
	return (0);
}
