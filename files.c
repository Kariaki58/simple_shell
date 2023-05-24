#include "shell.h"

/**
 * vec - print the environ
 */
void vec(void)
{
	int i;

	i = 0;
	while (environ[i])
		printf("%s\n", environ[i++]);
}

/**
 * token - create a string token
 * @string: string input
 * @dem: seperator
 * Return: return the token of a string
 */
char **token(char *string, char *dem)
{
	char *ll;
	char **path_token;
	int i;

	i = 0;
	ll = strtok(string, dem);
	path_token = malloc(100 * sizeof(char *));
	if (!path_token)
	{
		free(path_token);
		return (NULL);
	}
	while (ll)
	{
		path_token[i++] = ll;
		ll = strtok(NULL, dem);
	}
	return (path_token);
}

/**
 * path - get's a string path
 * @cmd: command input
 * Return: path of a string
 */
char *path(char *cmd)
{
	struct stat df;
	char *path;
	char *copy;
	char **array;
	char *cat = NULL;
	int i, len;

	path = getenv("PATH");
	i = 0, len = 0;
	copy = malloc(1 + strlen(path));
	if (!copy)
	{
		free(copy);
		return (NULL);
	}
	if (stat(cmd, &df) == 0)
		return (cmd);
	copy = strcpy(copy, path);
	array = token(copy, ":");
	while (array[i])
	{
		len = strlen(array[i]);
		if (array[i][len - 1] != '/')
			cat = strcat(array[i], "/");
		cat = strcat(array[i], cmd);
		if (stat(cat, &df) == 0)
			break;
		i++;
	}
	free(copy);
	if (array[i] == NULL)
	{
		free(array);
		return (NULL);
	}
	free(array);
	return (cat);
}

/**
 * line_ - check if line is empty
 * @buffer: command line to check
 * Return: is empty or not
 */

int line_(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
