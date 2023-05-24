#ifndef SHELL_H
#define SHELL_H

#define BUFF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	char *name;
	void (*func)(void);
} builin_t;

void cmdPrompt(char **, char **);

char **commandHandler(const char *, char);

char *pathHandler(char *);

int builtin(char *);

void free2D(char **);

void exiting();

void env();
#endif
