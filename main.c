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
 * main - entry point
 * @ac: input
 * @av: input 2
 * Return: return 0.
 */
int main(int ac, char **av)
{
	char buffer[BUFFER];
	char *args[100];
	int status_x;
	pid_t pid;

	while (1)
	{
		if (isatty(0))
			show_prompt();
		if (fgets(buffer, BUFFER, stdin) == NULL)
			break;
		buffer[strcspn(buffer, "\n")] = '\0';
		str_tok(buffer, args);
		pid = fork();
		if (pid < 0)
		{
			perror(av[ac - 1]);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve(args[0], args, NULL);
			perror(av[ac - 1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status_x);
		}
	}
	return (0);
}
