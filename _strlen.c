#include "holberton.h"

/**
*_strlen - return the length of string s
*@s:string
*Return:length of string s
**/
int _strlen(char *s)
{
int i;
for (i = 0; s[i] != '\0'; i++)
;
return (i);
}
