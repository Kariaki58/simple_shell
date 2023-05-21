#include "shell.h"

int simple_shell(char *argv[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		execve(argv[0], argv, environ);
		perror("Error");
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	return (status);
}
