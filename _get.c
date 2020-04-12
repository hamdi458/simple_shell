#include <stdint.h>
#include "shell.h"
/**
 **_realloc - fun
 *@ptr : var
 *@old_size : var
 *@new_size : var
 *Return: 0
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size > old_size)
	{
		free(ptr);
		ptr = malloc(new_size);
	}
	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

/**
 **_getline - getline
 *@buf : input line
 *@buf_size : size of input
 *@file : file
 *Return: 0
 */
ssize_t _getline(char **buf, size_t *buf_size, FILE *file)
{
	size_t length = 0;
	int c;
	size_t new;

	if (!buf || !buf_size || !file)
		return (-1);
	if (!*buf)
	{
		*buf = malloc(16);
		if (!*buf)
			return (-1);
		*buf_size = 16;
	}

	while (1)
	{
		c = getc(file);
		if (c == EOF || c == '\n')
			break;
		length++;
		if (length >= *buf_size)
		{
			new = *buf_size + 16;
			if (_realloc(*buf, length, new))
				*buf_size = new;
			else
				return (-1);
		}

		(*buf)[length - 1] = (char) c;
	}
	if (c == EOF)
		return (-1);

	(*buf)[length] = '\0';

	return (length);
}
