#include "shell.h"

/**
 * simple_shell - simple shell function
 * @argv: array of argument vector
 * @av: av
 * Return: Return status
 */
int simple_shell(char *argv[], char *av)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
		fprintf(stderr, "%s: No such file or directory\n", av);
	if (pid == 0)
	{
		execve(argv[0], argv, environ);
		perror("Error");
		grid_alloc(argv);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (status != 0)
			perror("Error");
	}

	return (status);
}
