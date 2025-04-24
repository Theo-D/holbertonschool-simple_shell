#include "shell.h"
/**
 * getPath - Parses and return PATH line from **environ as an array of strings.
 *
 * Return: An array of strings each containing a directory from PATH.
 */
char **getPath(void)
{
	char **envCpy;
	char *path = "PATH";
	char *subStr = strdup(path);
	char *pathLine;
	char **pathArr = NULL;
	int i = 0, lineLen = 0;

	if (environ == NULL || subStr == NULL)
		exit(2);

	envCpy = environ;

	while (*envCpy != NULL)
	{
		strncpy(subStr, envCpy[i], 4);
		subStr[4] = '\0';

		if (strcmp(subStr, path) == 0)
			break;
		i++;
	}

	free(subStr);

	lineLen = strlen(envCpy[i]);
	pathLine = malloc((lineLen - 5) + 1);
	strncpy(pathLine, envCpy[i] + 5, lineLen - 5);
	pathLine[lineLen - 5] = '\0';

	if (pathLine == NULL)
		exit(2);

	pathArr = tokenizeInput(pathLine);

	return (pathArr);
}
