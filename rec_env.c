#include "shell.h"
/**
 *_getenv - getenv recap the env path
 *@path: path
 *Return: 0
 */
char *_getenv(char *path)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		if (_strcmp(environ[i], path) == 0)
			return (environ[i]);
	}
	return (NULL);
}
/**
 * ver- verif
 *@c : th input
 * Return: 0
 */
int ver(char *c)
{
	struct stat buf;

	if (_getenv("PATH")[0] == ':')
	{
		if (stat(c, &buf) == 0)
			return (1);

	}
	return (0);
}
/**
 * result - concat a path
 *@s1: first string
 *@s2: second string
 *@s3 : command
 * Return: path
 */
char *result(char *s1, char *s2, char *s3)
{
	_strcpy(s1, s2);
	_strcat(s1, "/");
	_strcat(s1, s3);
	_strcat(s1, "\0");
	return (s1);
}
/**
 * rec_env - recover the path for cod
 *@cod: command input
 * Return: path
 */
char *rec_env(char *cod)
{
	int i = 0;
	char *path = _strdup(_getenv("PATH"));
	char *token = strtok(path, ":");
	char *tab_path[100];
	char *stat_path = NULL;
	struct stat buf;

	stat_path = malloc(100);
	if (ver(cod) == 1)
		return (_strdup(cod));

	while (token != NULL)
	{
		tab_path[i++] = token;
		token = strtok(NULL, ":");
	}
	tab_path[i] = NULL;
	i = 0;
	while (tab_path[i])
	{
		result(stat_path, tab_path[i], cod);
		if (stat(stat_path, &buf) == 0)
		{
			free(path);
			free_array(tab_path);
			return (stat_path);
		}
		i++;
	}
	free(path);
	free(stat_path);
	if (stat(cod, &buf) == 0)
		return (_strdup(cod));
	return (NULL);
}
