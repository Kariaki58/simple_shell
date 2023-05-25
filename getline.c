#include "shell.h"

ssize_t my_getline(char **lineptr, size_t *n, FILE *ss)
{
	size_t position = 0;
	int ll;

	if (lineptr == NULL || n == NULL || ss == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = malloc(sizeof(char) * (*n));
		if (*lineptr == NULL)
			return (-1);
	}
	while (1)
	{
		ll = fgetc(ss);

		if (ll == EOF)
		{
			if (position == 0)
				return (-1);
			else
				break;
		}
		(*lineptr)[position++] = ll;
		if (position > *n)
		{
			size_t size = *n + 128;
			char *ptr = realloc(*lineptr, size);
			if (ptr == NULL)
				return (-1);
			*lineptr = ptr;
			*n = size;
		}
		if (ll == '\n')
			break;
	}
	(*lineptr)[position] = '\0';
	return (position);
}
