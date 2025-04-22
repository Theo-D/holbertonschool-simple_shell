#include "shell.h"
/**
 *
 */
char **getPath(void)
{
	char **envCpy;
	char path[5] = "PATH";
	char *subStr = malloc(strlen(path) * sizeof(char));
	char *pathLine;
	char **pathArr = malloc(BUFF_SIZE);
	int i = 0, lineLen = 0;

	if (environ == NULL || subStr == NULL || pathArr == NULL)
		exit(2);

	envCpy = environ;

	while (*envCpy != NULL)
	{
		strncpy(subStr, envCpy[i], 4);
		subStr[5] = '\0';

		if (strcmp(subStr, path) == 0)
			break;
		i++;
	}

	free(subStr);
	
	lineLen = strlen(envCpy[i]);
	pathLine = malloc((lineLen * sizeof(char)) - 5);
	strncpy(pathLine, envCpy[i] + 5, (lineLen - 5));

	if (pathLine == NULL)
		exit (2);

	pathArr = tokenizeInput(pathLine);

	return (pathArr);
}
