#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*Spacing characters according to isspace() man page*/
#define SEP " \t\n\v\f\r"

/*Constant buffer size to use throughout the program*/
#define BUFF_SIZE 1024

/*points to an array of pointers to strings called the "environment"*/
extern char **environ;

void freeArr(char **av);

typedef struct inputToCmd{
	const char *cmd;
	int (*fun)(char **av);
} cmd_t;

int exitCmd(char **av);
int envCmd(char **av);
int executeCmd(char **av);

char *_getLine(void);
char **tokenizeInput(char *input);

void getCmd(char **av);

#endif
