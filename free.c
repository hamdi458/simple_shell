#include "shell.h"
/**
 * free_array - free array
 *@array: array of string
 * Return: 0
 */
void free_array(char **array)
{
	int i;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}
