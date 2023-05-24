#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;
void simple_shell(char *av);
char **token_array(char *buffer);
int check_line(char *buffer);
void environment(void);
char *my_getenv(char *environ_x);
char *find_path(char *buffer);
void show_prompt();
void str_tok(char *buffer, char *array[]);
#endif
