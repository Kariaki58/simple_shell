#include "shell.h"

/**
 * str_token - tokenised a string
 * @cpp: char cpp copy
 * Return: tokenised a string
 */
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

/**
 * find_path - find the path in getenv
 * @buffer: input buffer.
 * Return: return merge.
 */
char *find_path(char *buffer)
{
	char *bring = my_getenv("PATH"), **token, *merge = NULL, *cpp;
	int i = 0, len = 0;
	struct stat st;

	if (stat(buffer, &st) == 0)
		return (buffer);
	cpp = malloc(strlen(bring) + 1);
	strcpy(cpp, bring);
	token = str_token(cpp);
	while (token[i])
	{
		len = strlen(token[i]) - 1;
		if (token[i][len] != '/')
		{
			merge = malloc(strlen(token[i]) + 2);
			strcpy(merge, token[i]);
			strcat(merge, "/");
		}
		else
		{
			merge = malloc(strlen(token[i]) + 1);
			strcpy(merge, token[i]);
		}
		strcat(merge, buffer);
		
		/*merge = strcat(token[i], buffer);*/
		if (stat(merge, &st) == 0)
			break;
		i++;
	}
	free(cpp);
	if (token[i] == NULL)
	{
		free(token);
		free(merge);
		return (NULL);
	}
	free(token);
	return (merge);
}
