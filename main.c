#include "shell.h"
#define BUFFER 1024

/**
 * show_prompt - display prompt to user
 */
void show_prompt(void)
{
	printf("$ ");
}

/**
 * str_tok - string token
 * @buffer: buffer of string
 * @array: array of strings
 */
void str_tok(char *buffer, char *array[])
{
	char *token;
	char *arr[100];
	int i = 0, j;

	if (!buffer)
		return;
	token = strtok(buffer, " \n");
	while (token)
	{
		arr[i++] = token;
		token = strtok(NULL, " \n");
	}
	for (j = 0; j < i; j++)
	{
		array[j] = arr[j];
	}
	array[j] = NULL;
}

/**
 * execute - execute function
 * @paras: input 2
 */
void execute(char *paras[])
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror(__progname);
		_exit2();
	}
	else if (pid == 0)
	{
		execve(paras[0], paras, environ);
		perror(__progname);
		_exit2();
	}
	else
		waitpid(pid, NULL, 0);
}

/**
 * main - entry point
 * Return: return 0.
 */
int main(void)
{
	char *buffer = NULL, *args[100];
	char cmd[] = "/bin/ls";
	size_t n;

	while (1)
	{
		if (isatty(0))
			show_prompt();
		if (getline(&buffer, &n, stdin) == -1)
		{
			free(buffer);
			break;
		}
		buffer[strlen(buffer)] = '\0';
		str_tok(buffer, args);
		if (strcmp(args[0], "ls") == 0)
			args[0] = cmd;
		remove_spaces(args[0]);
		if (strcmp(args[0], "exit") == 0)
		{
			free(buffer);
			_exit2();
		}
		if (strcmp(args[0], "env") == 0)
		{
			vec();
			continue;
		}
		execute(args);
	}
	return (0);
}
