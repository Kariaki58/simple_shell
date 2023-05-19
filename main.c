#include "shell.h"

int main(int argc, char *argv[])
{
	char *buffer = NULL;
	char *args[100];
	size_t n;
	ssize_t read_stdin;
	pid_t pid;
	int status;

	if (argc > 2)
		return (0);
	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdin);
		read_stdin = getline(&buffer, &n, stdin);
		if (read_stdin < 0)
		{
			printf("%s: No such file or directory\n", argv[0]);
			continue;
		}
		status = simple_shell_no_args(buffer, args);
		pid = fork();
		if (pid < 0)
		{
			printf("%s: No such file or directory\n", argv[0]);
		}
		if (pid == 0)
		{
			if (status == 1)
				execve(args[0], args, NULL);
			printf("%s: No such file or directory\n", argv[0]);
		}
		else
			wait(NULL);
	}
	free(buffer);
	return (0);
}
