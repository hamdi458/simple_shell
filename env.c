#include "shell.h"


/**
 * envir - Write the environment
 *
 * @env:env variable
 * Return: nothing
 */

void envir(char **env)

{
int i;

for (i = 0; env[i]; i++)
{
write(1, env[i], _strlen(env[i]));
write(1, "\n", 1);
i++;
}
}
