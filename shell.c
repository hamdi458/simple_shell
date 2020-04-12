#include "shell.h"
#define DEL " \t\r\n\a"

/**
 * print_prompt - print prompt .

 * Return: Always 0.
 */
void print_prompt(int i)
{
	fflush(stdout);
	if(!i)
		_putstring("#:)$ ");
}
/**
 * process_line - Cut in pieces .
 *@line : input
 *@del : delimtre
 * Return: Always 0.
 */
char **process_line(char *line, char *del)
{
	int i = 0;
	char *token;
	char **commande;

	commande = NULL;
	token = NULL;
	commande = malloc(1048);
	token = _strtok(line, del);
	while (token != NULL)
	{
		commande[i] = token;
		token = _strtok(NULL, del);
		i++;
	}

	return (commande);
}

/**
 * fork_execve - fork and execve .
 *@line : input
 * Return: Always 0.
 */
void fork_execve(char **line, char **argv)
{
	int status = 0;
	int pid = fork();

	if (pid == -1)
		perror("fork");
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
		if (pid == 0)
	{
		if (rec_env(line[0]) == NULL)
		{
			_putstring(argv[0]);
			_putstring(" ");
			_putstring(line[0]);
			_putstring(" : command not found\n");
		}
		else
			execve(rec_env(line[0]), line, environ);
		exit(0);
	}
}
/**
 * main - main shell
 *
 * Return: Always 0.
 */

int main(int argc __attribute__((unused)), char **argv)
{
	char *line = NULL;
	size_t bufsize = 64;
	char **commande = NULL;
	unsigned int i = 0;

	line = (char *)malloc(bufsize * sizeof(char));
	if (line == NULL)
	{
		perror("Unable to allocate buffer");
		exit(0);
	}
	while (1)
	{
		print_prompt(i);
		signal(SIGINT, sig_handler);
		if (_getline(&line, &bufsize, stdin) == EOF)
		{
			_putstring("\n");
			break;
		}
		if (line == NULL)
			continue;
		commande = process_line(line, DEL);
		if (commande[0] == NULL)
			continue;
		if (verif_built(commande[0]) == 1)
			exec_built(commande);
		else
		{
			fork_execve(commande, argv);
		}
	}
	return (0);
}
