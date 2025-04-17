#include "shell.h"
/**
 * _getLine - Get input from user by calling getline().
 *
 * Return: Pointer to buffer allocated by getline().
 */
char *_getLine(void)
{
	char *line;
	/*char *currentDir;*/
	/*char cwd[BUFF_SIZE];*/
	size_t strSize;
	int charCount;

	/**
	 * currentDir = getcwd(cwd, BUFF_SIZE);
	 * if (currentDir != NULL)
	 *	printf("%s($)", currentDir);
	 * else
	 */
	 printf("($)");
	 /**
	 * Initialize string to NULL for getLine() to allocate memory under
	 * the hood
	 */
	line = NULL;
	charCount = getline(&line, &strSize, stdin);

	if (charCount == -1)
	{
		printf("Error or EoF\n");
		free(line);
		exit(EXIT_FAILURE);
		/*return (-1); Fix infinite printing of string*/
	}
	return (line);
}
