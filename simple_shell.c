#include "shell.h"

/**
 * simple_shell - simple shell function
 * @argv: array of argument vector
 * Return: Return status
 */
int simple_shell(char *argv[], char *av)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
		printf("%s: No such file or directory", av);
	if (pid == 0)
	{
		execve(argv[0], argv, environ);
		printf("%s: No such file or directory", av);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	return (status);
}
