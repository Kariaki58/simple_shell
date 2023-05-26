#include "shell.h"

int cd_command(char *path)
{
	char *token_array[100];

	printf("%s\n", path);
	str_tok(path, token_array);
	printf("%s\n", token_array[0]);
	return (1);
}
