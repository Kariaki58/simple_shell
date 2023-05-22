#include "shell.h"

/**
 * free_data - frees data structure
 *
 * @datash: data structure
 * Return: no return
 */
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @datash: data structure
 * @av: argument vector
 * Return: no return
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * execute - change to entry
 */

int execute(void)
{
	char *buffer;
	char **argv;
	size_t n;
	int i = 0;
	ssize_t buffer_size;
	int status;

	buffer_size = 0;
	status = 0;
	while (1)
	{
		fflush(stdin);
		printf("$ ");
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
			status = simple_shell(argv);
		else
			perror("Error");
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
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
