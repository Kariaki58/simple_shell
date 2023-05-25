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
 * @state: input
 * @paras: input 2
 */
void execute(char *state, char *paras[])
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror(state);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(paras[0], paras, environ);
		perror(state);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, NULL, 0);
}

/**
 * main - entry point
 * @ac: input
 * @av: input 2
 * Return: return 0.
 */
int main(int ac, char **av)
{
	char buffer[BUFFER], *args[100];

	while (1)
	{
		if (isatty(0))
			show_prompt();
		if (fgets(buffer, BUFFER, stdin) == NULL)
			break;
		buffer[strcspn(buffer, "\n")] = '\0';
		str_tok(buffer, args);
		remove_spaces(buffer);
		if (strcmp(buffer, "exit") == 0)
		{
			exit(0);
			break;
		}
		if (strcmp(buffer, "env") == 0)
		{
			vec();
			continue;
		}
		execute(av[ac - 1], args);
	}
	return (0);
}
