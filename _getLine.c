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
	ssize_t charCount;

	/**
	 * currentDir = getcwd(cwd, BUFF_SIZE);
	 * if (currentDir != NULL)
	 *	printf("%s($)", currentDir);
	 * else
	 */
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
		/*fprintf(stderr, "Error or EoF\n");*/
		free(line);
		exit(-1);
	}
	return (line);
}
