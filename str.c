#include "shell.h"

/**
 * _strcmp - concatenates two strings.
 * @s1 : The pointer
 * @s2 : chaine
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i, j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
		j++;
	for (i = 0; i < j; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}


/**
 * _strcat - concatenates two strings.
 * @dest : The pointer
 * @src : chaine
 * Return: Always 0.
 */
char *_strcat(char *dest, char *src)
{
	int j = 0;
	int i = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	j = i;
	i = 0;
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j + 1] = '\0';
	return (dest);
}
