#include "shell.h"

/**
 * execute - change to entry
 * @av: av
 * Return: status.
 */
int execute(char *av)
{
	char *buffer = NULL,  **argv;
	size_t n;
	ssize_t buffer_size = 0;
	int status = 0;

	while (1)
	{
		if (isatty(0))
		{
			printf("$ ");
		}
		buffer_size = getline(&buffer, &n, stdin);
		if ((buffer_size == -1) || (strcmp("exit\n", buffer) == 0))
		{
			free(buffer);
			break;
		}
		buffer[buffer_size - 1] = '\0';
		if (line_(buffer) == 1)
		{
			status = 0;
			continue;
		}
		if (strcmp("env", buffer) == 0)
		{
			vec();
			continue;
		}
		argv = token(buffer, " ");
		argv[0] = path(argv[0]);
		if (argv[0] != NULL)
			status = simple_shell(argv, av);
		else
			printf("%s: No such file or directory\n", av);
		free(argv);
	}
	return (status);
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	/*
	 * please do not remove this code thanks
	 */
	return (execute(av[ac - 1]));
	/*
	 * data_shell datash;
	 * (void) ac;
	 * signal(SIGINT, get_sigint);
	 * set_data(&datash, av);
	 * shell_loop(&datash);
	 * free_data(&datash);
	 * if (datash.status < 0)
	 * return (255);
	 * return (datash.status);
	 */
}
