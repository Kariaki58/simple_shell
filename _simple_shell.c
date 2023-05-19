#include "shell.h"

int simple_shell_no_args(char *cmd, char *argv[])
{
	char *buffer;
	int i, count;

	i = 0;
	count = 0;
	buffer = strtok(cmd, " \n");
	while (buffer)
	{
		count++;
		argv[i++] = buffer;
		buffer = strtok(NULL, " \n");
	}
	if (count >= 2)
	{
		argv[i] = NULL;
		return 0;
	}
	argv[i] = NULL;
	return 1;
}
