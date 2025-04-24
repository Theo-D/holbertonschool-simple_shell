#include "shell.h"
/**
 * _getLine - Get input from user by calling getline().
 *
 * Return: Pointer to buffer allocated by getline().
 */
char *_getLine(void)
{
	char *line;
	size_t strSize;
	ssize_t charCount;

	if (isatty(STDIN_FILENO))
		printf("($)");
	 /**
	 * Initialize string to NULL for getLine() to allocate memory under
	 * the hood
	 */
	line = NULL;
	charCount = getline(&line, &strSize, stdin);

	if (charCount == -1)
	{
		free(line);
		exit(0);
	}
	return (line);
}
