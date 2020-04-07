#include"shell.h"

/**
 * rec_env - recover Path
 * @line: line enter
 *Return: NULL
 */
char *rec_env(char *line)
{
	struct stat buf;
	int i = 0;
	char* s;
	char* args[10];
	s = getenv("PATH");
	args[i] = strtok(s,":");
	if(args[i] == NULL)
                return(NULL);
        while (args[i] != NULL)
        {
                i++;
                args[i] = strtok(s,":");
        }
	i = 0;
	while(args[i])
	{
		_strcat(args[i], "/");
		_strcat(args[i], line);
		if (stat(args[i], &buf) == 0)
			return args[i];
		i++;
	}
	return (NULL);
}
