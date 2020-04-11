#ifndef SHELL_H
#define SHELL_H
#include <stdbool.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
extern char **environ;
int verif_built(char *cmd);
void free_array(char **array);
void exec_built(char **built_in);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);
void _putstring(char *c);
void sigintHandler(int sig);
int _strlen(char *s);
char *rec_env(char *c);
void sig_handler(int sig);
int _strcmp(char *s1, char *s2);
char *_strdup(char *ch);
#endif
