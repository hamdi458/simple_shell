#include "shell.h"
#define DEL " \t\r\n\a"
void remove_endof_line(char line[])
{
        int i = 0;
        while (line[i] != '\n')
                i++;
        line[i] = '\0';
}
char **process_line(char *line, char *del)
{
        int i = 0;
        char *token;
	char **commande;

	commande = NULL;
	token = NULL;
	commande = malloc(1048);
        token = strtok(line, del);
        while (token != NULL)
        {
		commande[i] = token;
		token = strtok(NULL,del);
		i++;
        }

        return (commande);
}


void fork_execve(char **line)
{
	pid_t pid = 0;
	int status = 0;

	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 1)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else if (pid == 0)
	{
		if (execve(rec_env(line[0]), line, NULL) == -1)
			perror("shell");
		exit(-1);
	}
}

int main()
{
	char* line = NULL;
	size_t bufsize = 64;
	char **commande = NULL;
	line = (char *)malloc(bufsize * sizeof(char));
	if( line == NULL)
        {
		perror("Unable to allocate buffer");
                exit(1);
        }
	_putstring("$> ");
	while (getline(&line, &bufsize, stdin))
	{
		commande = process_line(line, DEL);
		if (commande[0] == NULL)
			perror("Error:");
		else
			fork_execve(commande);
		_putstring("$> ");
	}
	free_array(commande);
	free(line);
	return(0);
}
