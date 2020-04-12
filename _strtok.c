#include "shell.h"
/**
 * _strtok - strtok.
 *@str : string
 *@del : delimiters
 * Return: 0.
 */
char *ch = NULL;
char *_strtok(char *str, char *del)
{
	int i, len = _strlen(del);
	char *start_copy;

	if (ch == NULL && str)
		ch = str;
	if ((!str && ch == NULL) || !del)
		return (NULL);
	start_copy = ch;
	while (1)
	{
		i = 0;
		while (del[i])
		{
			if (*start_copy == del[i])
			{
				start_copy++;
				break;
			}
			i++;
		}
		if (i == len)
			break;
	}
	ch = start_copy;
	if (*start_copy == '\0')
	{
		ch = NULL;
		return NULL;
	}
	while (*ch != '\0')
	{
		i = 0;
		while (del[i])
		{
			if (*ch == del[i])
			{
				*ch = '\0';
				break;
			}
			i++;
		}
		ch ++;
		if (i < len)
			break;
	}
	return (start_copy);
}
