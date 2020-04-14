#include "shell.h"
/**
 *_help - help users.
 *@av: arguments.
 *
 *
 */
void _help(char **av)
{
	_putstring(av[1]);

	if (!av[1])
	{
		_putstring("Welcome to :)'s simple shell!.\n");
		_putstring("Usage: help [BUILTIN].\n");
	}
	else
	{

		if (_strcmp("cd", av[1]) == 0)
		{
			_putstring("Change the shell working directory.\n");
			_putstring("Usage: cd <directory>\n");
		}

		else if (_strcmp("exit", av[1]) == 0)
		{
			_putstring("Exit the :) shell.\n");
			_putstring("Usage: exit\n");

		}
		else if (_strcmp("env", av[1]) == 0)
		{
			_putstring("Prints the content of :) enviroment\n");
			_putstring("Usage: env\n");

		}
		else if (_strcmp("help", av[1]) == 0)
		{
			_putstring("Usage: help [BUILTIN]\n");
			_putstring("Usage: help\n");
		}
		else
		{
			_putstring("Hello i'm :) and i'm working on this\n");
		}
	}

}


/**
 * verif_built - verif built or not
 *@cod: command input
 * Return: 1 or 0
 */
int verif_built(char *cod)
{
	int i;
	char *built_in[] = {"help", "env", "exit", "pwd", "cd", NULL};

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
void exec_built(char **built, char **argv)
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
				if (chdir(built[1]) == -1)
					perror("chdir");
		}
		else
			if (i == 0)
				exit(127);
			else
				if (_strcmp(built[0], "help") == 0)
					_help(argv);
}
