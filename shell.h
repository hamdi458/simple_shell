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
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void print_number(int n);
int verif_built(char *cmd);
char *_getenv(char *path);
void free_array(char **array);
char *_strtok(char *str, char *del);
void exec_built(char **built_in, char **argv);
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
int _getline(char **pline_buf, size_t *pn, FILE *fin);
#endif
