#include "main.h"

/**
 * _realloc - function that reallocates a buffer
 * @initial: a pointer to the buffer
 * @initial_size: the current size buffer size
 * @new_size: desired size
 * Return: NULL If memory allocation fails,
 * Otherwise, a pointer to new buffer.
 */
static void *_realloc(void *initial, size_t initial_size, size_t new_size)
{
	void *new = NULL;

	if (initial)
	{
		if (initial_size)
		{
			initial = malloc(initial_size);
			if (new)
			{
				_memcpy(new, initial, initial_size < new_size ? initial_size : new_size);
				free(initial);
			}
		}
		else
		{
			free(initial);
		}
	}
	return (new);
}

/**
 * getline_next - function that reads a line of input
 * @buf: a pointer to the static buffer
 * @line: the address of a pointer to the line
 * @size: the address of a pointer to the size
 * @n: number of characters to copy from buffer
 * Return: NULL If memory allocation fails,
 * Otherwise, a pointer to the line of input.
 */
static char *getline_next(buf_t *buf, char **line, size_t *size, size_t n)
{
	char *tmp = NULL;


	if (*line)
	{
		tmp = _realloc(*line, *size, *size + n);

	else
		tmp = malloc(n + 1);

	if (tmp)
	{
		*line = tmp;

		if (*size)
		{
			*size -= 1;
		}
		_memcpy(*line + *size, buf->next, n);
		*size += n;

		(*line)[*size] = '\0';
		*size += 1;
	}
	else
	{
		free(*line);
		*line = NULL;
		*size = 0;
	}
	return (*line);
}

/**
 * getline_buff - function that creates, gets, and deletes buffers
 * @table: buffers indexed by file descriptor
 * @descriptor: file descriptor
 * Return: NULL or a pointer to the buffer associated with descriptor
 */
static buf_t *getline_buff(buf_table_t *table, const int descriptor)
{
	buf_table_node_t *item = NULL;
	size_t indx = descriptor % GETLINE_TABLE_SIZE;

	if (table)
	{
		if (descriptor < 0)
		{
			for (indx = 0; indx < GETLINE_TABLE_SIZE; indx += 1)
			{
				while ((item = (*table)[indx]))
				{
					(*table)[indx] = item->next;
					free(item);
				}
			}
		}
		else
		{
			item = (*table)[indx];
			while (item && item->descriptor != descriptor)
			{
				item = item->next;
			}
			if (item == NULL)
			{
				item = malloc(sizeof(*item));
				if (item)
				{
					item->descriptor = descriptor;
					item->buf.next = NULL;
					item->buf.remaining = 0;
					item->next = (*table)[indx];
					(*table)[indx] = item;
				}
			}
		}
	}
	return (item ? &item->buf : NULL);
}

/**
 * _getline_ - function that reads a line of input
 * @descriptor: file descriptor
 * Return: NULL if an error occurs or there are no more lines,
 * Otherwise, return the next line of input.
 */
char *_getline_(const int descriptor)
{
	static buf_table_t table;
	buf_t *buf = _getline_buf(&table, descriptor);
	char *line = NULL;
	size_t size = 0;
	ssize_t eol = 0, n_read = 0;

	if (buf)
	{
		do {
			if (buf->remaining == 0)
				buf->next = buf->buffer;
			if (n_read)
			{
				buf->remaining = n_read;
			}
			if (buf->remaining)
			{
				eol = _memchr(buf->next, '\n', buf->remaining);
				if (eol == -1)
				{
					if (getline_next(buf, &line, &size, buf->remaining))
					{
						buf->next += buf->remaining, buf->remaining = 0;
					}
					else
						break;
				}
				else
				{
					if (getline_next(buf, &line, &size, eol + 1))
					{
						buf->next += eol + 1, buf->remaining -= eol + 1;
					}
					break;
				}
			}
		} while ((n_read = read(fd, buf->buffer, GETLINE_BUFFER_SIZE)) > 0);
		if (n_read == -1)
		{
			free(line);
			line = NULL;
			size = 0;
		}
	}
	return (line);
}
