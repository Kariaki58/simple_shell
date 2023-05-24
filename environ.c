#include "shell.h"

/**
 * environment - get the environment
 */
void environment(void)
{
	int i;

	i = 0;
	while (environ[i])
		printf("%s\n", environ[i++]);
}

/**
 * my_getenv - get environment
 * @environ_x: input env
 * Return: return my_get.
 */
char *my_getenv(char *environ_x)
{
	int i = 0, j, status;
	char *my_get;

	while (environ[i])
	{
		status = 1;

		for (j = 0; environ[i][j] != '='; j++)
			if (environ[i][j] != environ_x[j])
				status = 0;
		if (status == 1)
			break;
		i++;
	}
	my_get = &environ[i][j + 1];
	return (my_get);
}
