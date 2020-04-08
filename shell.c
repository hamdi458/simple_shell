#include "shell.h"
#define DEL " \t\r\n\a"
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
        return (1);
}


void print_prompt ()
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

int main()
{
	char* line;
	size_t bufsize = 64;
	char *t[100];

	line = (char *)malloc(bufsize * sizeof(char));
	if( line == NULL)
        {
		perror("Unable to allocate buffer");
                exit(1);
        }
	while (1)
	{
		print_prompt();
		getline(&line, &bufsize, stdin);
		process_line(t, line);
		execvp(t[0], t);
		free(line);
	}
	return(0);
}
