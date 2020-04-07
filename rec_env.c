#include"shell.h"

/**
 * rec_env - recover Path
 * @line: line enter
 *Return: NULL
 */
char *rec_env(char *line)
{
	struct stat buf;
	char* stat;
	char *s;
	int i = 0;
	char* args[];
	s = getenv("PATH");
	args[i] = strtok(line,":");
	if(args[i] == NULL)
                return(NULL);
        while (args[i] != NULL)
        {
                i++;
                args[i] = strtok(line,":");
        }
	i = 0;
	while(args[i])
	{
		_strcat(t[i], "/");
		_strcat(t[i], line);
		if (stat(t[i], &buf) == 0)
			return t[i];
		i++;
	}
	return (NULL);
}
