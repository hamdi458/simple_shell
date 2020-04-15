#include "shell.h"

/**
 * print_number - print number.
 *@n : the number
 * Return: Always 0.
 */
void print_number(int n)
{
	unsigned int num = n;

	if (n < 0)
	{
		_putchar('-');
		num = -num;
	}
	if ((num / 10) > 0)
		print_number(num / 10);
	_putchar((num % 10) + '0');
}

/**
 * _strcpy - Returns the length of a string
 * @dest: The string whose length will be returned
 * @src: djjhfhd
 * Return: the string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - copy strdup
 * @ch: string to copie
 * Return: 0
 */
char *_strdup(char *ch)
{
	char *ch_d;
	unsigned int i = 0, s = 0;

	if (ch == NULL)
		return (NULL);

	while (ch[s])
		s++;

	ch_d = malloc(s + 1);

	if (ch_d == NULL)
		return (NULL);

	while (ch[i])
	{
		ch_d[i] = ch[i];
		i++;
	}
	return (ch_d);
}

/**
 * _strcmp - compare two strings.
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

	int s = _strlen(dest);

	while (src[j] != '\0')
	{
		dest[s] = src[j];
		s++;
		j++;
	}
	dest[s] = '\0';
	return (dest);
}
