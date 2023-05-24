#include "shell.h"

/**
 * vec - print environment
 */
void vec(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
}
