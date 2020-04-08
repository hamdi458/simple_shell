#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char **environ;
void free_array(char **array);
char *_strcat(char *dest, char *src);
int _putchar(char c);
void _putstring(char *c);
char *rec_env(char *c);
#endif
