#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;
char **tok_str(char *string, char *del);
char *path(char *cmd);
char **token(char *string, char *dem);
int simple_shell(char *argv[], char *av);
int line_(char *buffer);
void vec(void);
int execute(char *av);
void grid_alloc(char **grid);

#endif
