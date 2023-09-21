#include "shell.h"

/**
 * _fork - a function that forks a child process and executes a cmd
 * @token_arr: an array of strings representing the command and its args
 * @cmd: the command to execute
 *
 * Return: 0 on success, 1 if error occurs
 */
int _fork(char *cmd, char **token_arr)
{
	int s;
	int execve_error;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("_fork() Error: fork child unable to create");
		return (-1);
	}
	if (pid == 0)
	{
		execve_error = execve(cmd, token_arr, __environ);
		if (execve_error == -1)
		{
			perror("execve: ");
			return (-1);
		}
	}
	else
	{
		wait(&s);
		free(cmd);
		if (WIFEXITED(s))
		{
			s = WEXITSTATUS(s);
		}
		if (!isatty(STDIN_FILENO))
		{
			return (s);
		}
	}
	return (0);
}
