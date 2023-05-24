#include "shell.h"

/**
 * execute - execute
 * @args: prints args
 * @av: input av.
 * Return: return status.
 */
int execute(char **args, char *av)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
		perror(av);
	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror(av);
	}
	else
		wait(&status);
	return (status);
}
