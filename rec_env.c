#include"shell.h"
#include <string.h>
/**
 * rec_env - recover Path
 * @line: line enter
 *Return: NULL
 */
char *rec_env(char *line)
{
	struct stat buf;
	char *str;
	char *s;
	char *token;
	int i = 0;
	char* args[100];
	char* tab[100];

	s = getenv("PATH");
        token = strtok(s,":");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL,":");
	}
        i = 0;
	while (args[i])
	{
		str = (char*)malloc(100);
		_strcat(str, args[i]);
		_strcat(str, "/");
		_strcat(str,line);
		tab[i] = str;
		if (stat(tab[i], &buf) == 0)
		{
			return (tab[i]);
		}
		i++;
	}
	return (NULL);
}
