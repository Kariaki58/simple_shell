#include "shell.h"

/**
 * grid_alloc - free grid memory and grid
 * @grid: heap array of grid
 */
void grid_alloc(char **grid)
{
	int i;

	for (i = 0; grid[i]; i++)
		free(grid[i]);
	free(grid);
}

/**
 * execute - change to entry
 * @av: av
 * Return: status.
 */
int execute(char *av)
{
	char *buffer = NULL,  **argv, *prompt = "$ ";
	size_t n;
	ssize_t buffer_size = 0;
	int status = 0;

	while (1)
	{
		if (isatty(0))
			write(STDIN_FILENO, prompt, 2);
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
			perror(av);
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
		{
			perror(av);
			continue;
		}
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
	return (execute(av[ac - 1]));
}
