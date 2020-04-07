#include "shell.h"
#define DEL " \t\r\a\n"
int process_line(char *args[], char line[])
{
        int i = 0;
        args[i] = strtok(line, DEL);
        if(args[i] == NULL)
                return(1);
        while (args[i] != NULL)
        {
                i++;
                args[i] = strtok(line, DEL);
        }
        args--;
        return (1);
}

int main()
{
	char* line;
	pid_t pid;
	size_t bufsize = 32;
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
							perror("Error");
							exit(0);
						}
			}
		}
			else
				wait(NULL);
	}
	return(0);
}





/**
 * signal_handler - handles ^C input
 * @sig: signal value
 * Return: void
 */
void signal_handler(int sig)
{
	(void) sig;
	write("\n$ ");
}
