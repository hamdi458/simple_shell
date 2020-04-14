#include "shell.h"
/**
 * verif_built - verif built or not
 *@cod: command input
 * Return: 1 or 0
 */
int verif_built(char *cod)
{
	int i;
	char *built_in[] = {"exit", "pwd", "cd", NULL};

	for (i = 0; built_in[i]; i++)
	{
		if (_strcmp(built_in[i], cod) == 0)
			return (1);
	}
	return (0);
}

/**
 * exec_built - exec built
 *@built : built input
 * Return: void
 */
void exec_built(char **built)
{
	char cwd[PATH_MAX];
	int i;

	i = _strcmp(built[0], "exit");
	if (_strcmp(built[0], "pwd") == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s\n", cwd);
		else
		perror("getcwd()");
	}
	else
		if (_strcmp(built[0], "cd") == 0)
		{
			if (built[1] == NULL)
				chdir(getenv("HOME"));
			else
				if(chdir(built[1]) == -1)
				perror("chdir");
		}
		else
			if (i == 0)
				exit(127);
}
