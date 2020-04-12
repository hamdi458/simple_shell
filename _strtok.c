#include <stdio.h>
#include<string.h>
#include "shell.h"

char *ch = NULL;
char *_strtok(char *str, char *del)
{
	int i;
	int len = strlen(del);
	char *start_copy;
	if (ch == NULL && str)
	{
		ch = str;
	}
	if ((!str && ch == NULL) || !del)
		return(NULL);

	start_copy = ch;
	while(1) {
		for(i = 0; i < len; i ++) {
			if(*start_copy == del[i]) {
				start_copy ++;
				break;
			}
		}
		if(i == len) {
			break;
		}
	}
	ch = start_copy;
	if(*start_copy == '\0') {
		ch = NULL;
		return NULL;
	}

	while(*ch != '\0') {
		for(i = 0; i < len; i ++) {
			if(*ch == del[i]) {
				*ch = '\0';
				break;
			}
		}
		ch ++;
		if (i < len)
			break;
	}
	return start_copy;
}
