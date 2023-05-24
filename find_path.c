#include "shell.h"

char **str_token(char *cpp)
{
	char *ll;
	char **tokenised;
	int i = 0;

	ll = strtok(cpp, ":");
	tokenised = (char **)malloc(sizeof(char *) * 100);
	if (!tokenised)
	{
		free(tokenised);
		return (NULL);
	}
	while (ll)
	{
		tokenised[i++] = ll;
		ll = strtok(NULL, ":");
	}
	return (tokenised);
}

char *find_path(char *buffer)
{
	char *bring = my_getenv("PATH");
	char **token;
	char *merge = NULL;
	char *cpp;
	int i = 0, len = 0;
	struct stat st;

	if (stat(buffer, &st) == 0)
		return (buffer);
	cpp = malloc(strlen(bring) + 1);
	cpp = strcpy(cpp, bring);
	token = str_token(cpp);
	while (token[i])
	{
		len = strlen(token[i]) - 1;

		if (token[i][len] != '/')
			merge = strcat(token[i], "/");
		merge = strcat(token[i], buffer);
		if (stat(merge, &st) == 0)
			break;
		i++;
	}
	free(cpp);
	if(token[i] == NULL)
	{
		free(token);
		return (NULL);
	}
	free(token);
	return (merge);
}
