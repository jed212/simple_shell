#include "shell.h"

/**
 * _getline_ - function that reads a line from standard input
 * @input: the input
 * @malloc_bytes_allocated: pointer to a size_t var tracking
 * the number of bytes allocated for input.
 * @status: the exit status if error occurs
 *
 * Return: -1 on failure, greater than 0 on success
 */
ssize_t _getline_(char **input,
		size_t *malloc_bytes_allocated, int status)
{
	ssize_t chars_read;

	display_prompt();
	chars_read = getline(input, malloc_bytes_allocated, stdin);
	if (chars_read == -1)
	{
		free(*input);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}
	return (chars_read);
}
