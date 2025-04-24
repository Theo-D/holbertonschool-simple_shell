#include "shell.h"
/**
 * tokenizeInput - Breaks string returned by _getline into tokens and stores
 * them in array of strings.
 * @line: Line returned by _getline().
 * @sep: string separating tokens.
 *
 * Return: Array of strings.
 */
char **tokenizeInput(char *line, char *sep)
{
	size_t buff = BUFF_SIZE, i = 0;
	char *newLine = strdup(line);
	char *token = strtok(newLine, sep);
	char **tokenArr = malloc(buff * sizeof(char *));

	if (line == NULL)
	{
		free(line);
		exit(0);
	}

	while (token != NULL)
	{
		tokenArr[i] = strdup(token);
		token = strtok(NULL, sep);
		i++;
	}
	tokenArr[i] = '\0';
	free(line);
	free(newLine);

	return (tokenArr);
}
/**
 * exitHandler - Handles exit status according to received error tracking
 * variable.
 * @errTrack: Integer used to track return values throughout the code.
 */
void exitHandler(int errTrack)
{
	if (errTrack == -3)
		exit(127);
}
/**
 * freeArr - Frees array of string.
 * @av: Array to be freed.
 *
 * Return: Nothing
 */
void freeArr(char **av)
{
	int i = 0;

	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
/**
 * checkAccess - Checks if file is accessible at given path.
 * @execPath: Path of the file to be accessed.
 *
 * Return: 0 if file is accessible. Else returns according return code
 * to be handled in exitHandler.c.
 */
int checkAccess(char *execPath)
{
	if (access(execPath, F_OK) == -1)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", execPath);
		return (-3);
	}
	return (0);
}
