#include "shell.h"

int main(void)
{
	char *buffer;
	char **argv;
	size_t n;
	ssize_t buffer_size;
	int status;

	buffer = NULL;
	buffer_size = 0;
	status = 0;
	while (1)
	{
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
