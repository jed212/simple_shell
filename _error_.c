#include "shell.h"

/**
 * error_not_found - function that prints a custom error for not found cmd
 * @arvs: represents command line arguments
 * @token_arr: the tokenized arr of strings
 * @cmd_num: a counter indicating the command number
 *
 * Return: 127 exit status for command not found error
 */
int error_not_found(char **arvs, char **token_arr, size_t cmd_num)
{
	char *error_str;
	char *cmd_num_str = _itoa(cmd_num);

	int size = (strlen(arvs[0]) + (2 * strlen(": ")) +
			digit_counter(cmd_num) + strlen(token_arr[0]) +
			strlen(": not found\n") + 1);

	malloc_char_(&error_str, size, "error_not_found Error: malloc error");

	strcat(error_str, cmd_num_str);
	strcat(error_str, ": ");
	strcpy(error_str, arvs[0]);
	strcat(error_str, ": ");
	strcat(error_str, token_arr[0]);
	strcat(error_str, ": not found\n");
	strcat(error_str, "\0");

	write(STDERR_FILENO, error_str, strlen(error_str));
	free(error_str);
	free(cmd_num_str);

	return (127);
}
