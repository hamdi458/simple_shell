#include "shell.h"

/**
 *cmddir - Concatenate directory to command line
 *@dir: directory
 *@arg: argument
 *Return:buff
 */


char *cmddir(char *dir, char *arg)
{


int i, j, len1, len2;

char *buff;

len1 = _strlen(dir);
len2 = _strlen(arg);

buff = malloc(sizeof(char) * len1 + len2 + 1);

for (i = 0; i < len1; i++)
{
buff[i] = dir[i];
}

for (j = 0; i < len1 + len2; i++, j++)
{
buff[i] = arg[j];
}
buff[i] = '\0';
return (buff);
}