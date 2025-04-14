#include "shell.h"
/**
 *
 */
char *_getLine(void)
{
	char *string;
	char *currentDir = NULL;
	char cwd[BUFF_SIZE];
	size_t strSize;
	int charCount;

	currentDir = getcwd(cwd, sizeof(cwd));
	printf("%s($)", currentDir);
	/** 
	 * Initialize string to NULL for getLine() to allocate memory under
	 * the hood
	 */
	string = NULL;
	charCount = getline(&string, &strSize, stdin);

	if (charCount == -1)
	{
		printf("Error or EoF\n");
		/*return (-1); Fix infinite printing of string*/
	}

	return (string);
}

char **tokenizeInput(char *cmd)
{

	/*Transform *token into **tokens*/
	char *token;

	token = strtok(cmd, SEP);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, SEP);
	}
	return (token);
}
