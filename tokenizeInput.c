#include "shell.h"
/**
 * tokenizeInput - Breaks string returned by _getline into tokens and stores
 * them in array of strings.
 * @line: Line returned by _getline().
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
		/**
		* printf("%s\n", token);
		* if (i >= buff)
		* {
		*	buff *= 2;
		*	temp = realloc(tokenArr, buff * sizeof(char*));
		*	if (!temp)
		*	{
		*		free(tokenArr);
		*		return NULL;
		*	}
		*	tokenArr = temp;
		*}
		*/
		tokenArr[i] = strdup(token);
		token = strtok(NULL, sep);
		i++;
	}
	tokenArr[i] = '\0';
	free(line);
	free(newLine);

	return (tokenArr);
}
