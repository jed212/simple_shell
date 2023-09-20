#include "main.h"

/**
 * read_input - a function that gets the input
 * @shellIinfo: represents shell information
 *
 * Return: returns the line size
 */
bool read_input(info_t *shellInfo)
{
	char *line = NULL;
	char *temp = NULL;

	if (shellInfo->interactive)
	{
		write(STDERR_FILENO, "$ ", 2);
	}
	shellInfo->lineno += 1;

	while (read_line(&shellInfo->line, shellInfo->fileno) &
		(QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
	{
		temp = line;
		line = strjoin(NULL, "", temp, shellInfo->line);
		free(temp);
		free(shellInfo->line);
		if (shellInfo->interactive)
		{
			write(STDERR_FILENO, "> ", 2);
		}
		shellInfo->lineno += 1;
	}
	if (line)
	{
		temp = shellInfo->line;
		shellInfo->line = strjoin(NULL, "", line, temp);
		free(line);
		free(tmp);
	}
	return (shellInfo->line);
}


/**
 * read_line - function that reads a single line
 * @lineptr: a line buffer
 * @descriptor: the file descriptor to read from
 *
 * Return: returns an ending quote state
 */
quote_state_t read_line(char **lineptr, int descriptor)
{
	char *line = *lineptr = _getline(descriptor);
	static quote_state_t state = QUOTE_NONE;
	size_t indx = 0;

	if (line)
	{
		switch (state & (QUOTE_DOUBLE | QUOTE_SINGLE))
		{
		case QUOTE_DOUBLE:
		case QUOTE_SINGLE:
			do {
				index += quote_state_len(line + index, state);
				if (line[indx] == '\0')
				{
					continue;
				}
				if (state & (QUOTE_DOUBLE | QUOTE_SINGLE))
				{
					indx += 1;
				}
		case 0:
				state = quote_state(line[indx]);
				if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
					indx += 1;
			} while (line[indx]);
		}
	}
	return (state);
}
