#include "shell.h"

/**
 * check_line - check if line is empty
 * @buffer: input buffer
 * Return: return int
 */
int check_line(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] != ' ')
		{
			return (0);
		}
	}
	return (1);
}

/**
 * token_array - get array from buffer
 * @buffer: input bbuffer
 * Return: return path
 */
char **token_array(char *buffer)
{
	char **path;
	char *ll;
	int i = 0;

	path = (char **)malloc(sizeof(char *) * 100);
	if (!path)
		return (NULL);
	ll = strtok(buffer, " ");
	while (ll)
	{
		path[i++] = strdup(ll);
		ll = strtok(NULL, " ");
		i++;
	}
	path[i] = NULL;
	return (path);
}

/**
 * main - entry point
 * @ac: ac
 * @av: av
 * Return: status
 */
int main(int ac, char **av)
{
	char *buffer = NULL;
	size_t n = 0;
	ssize_t readline = 0;
	char **args;
	int status, count = 0;
	char *prompt = "$ ", *path;

	while (1)
	{
		count++;
		if (isatty(0))
			write(STDOUT_FILENO, prompt, strlen(prompt));
		readline = getline(&buffer, &n, stdin);
		if (readline == -1 || strcmp("exit\n", buffer) == 0)
		{
			free(buffer);
			free(args);
			break;
		}
		buffer[readline - 1] = '\0';
		if (strcmp("env", buffer) == 0)
		{
			environment();
			continue;
		}
		if (check_line(buffer) == 1)
		{
			status = 0;
			continue;
		}
		args = token_array(buffer);
		path = find_path(args[0]);
		if (path != NULL)
		{
			free(args[0]);
			args[0] = path;
			execute(args, av[ac - 1]);
		}
		else
			perror(av[ac - 1]);
	}
	free(buffer);
	free(args);
	return (status);
}
