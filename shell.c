#include "shell.h"
#define DEL " "
void remove_endof_line(char line[])
{
        int i = 0;
        while (line[i] != '\n')
                i++;
        line[i] = '\0';
}
int process_line(char *args[], char line[])
{
        int i = 0;
        char *token;
	remove_endof_line(line);
        token = strtok(line," ");
        while (token != NULL)
        {
                args[i] = token;
                i++;
		token = strtok(NULL," ");
        }
        return (0);
}

int main()
{
	char* line;
	pid_t pid;
	size_t bufsize = 64;
	char* t[10];
	int r_exec;
	_putstring("#cisfun$ ");
	line = (char *)malloc(bufsize * sizeof(char));
	if( line == NULL)
        {
		perror("Unable to allocate buffer");
                exit(1);
        }
	while (getline(&line, &bufsize, stdin))
	{
		process_line(t, line);
		pid = fork();
		if (pid == 0)
		{
			r_exec = execve(t[0], t, NULL);
			if (r_exec == -1)
			{
				r_exec = execve(rec_env(t[0]), t, NULL);
						if (r_exec == -1)
						{
							printf("Error");
							exit(0);
						}
			}
		}
		else
			wait(NULL);
		_putstring("#cisfun$ ");

	}
	return(0);
}
