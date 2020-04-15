#include "shell.h"

/**
 *_strlen - return the length of string s
 *@s:string
 *Return:length of string s
 **/
int _strlen(char *s)
{
	int i =  0;

	while (s[i])
		i++;
	return (i);
}
