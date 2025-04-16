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

	currentDir = getcwd(cwd, BUFF_SIZE);
	/*system("/bin/jp2a https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQ5kivFairrJqfDe9OEGo68L5PowZPJnGWcdA&s");*/
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
/**
 *
 */
char **tokenizeInput(char *line)
{
	int i = 0;
	char *token;
	char **tokenArr = malloc(BUFF_SIZE * sizeof(*token));

	token = strtok(line, SEP);
	while (token != NULL)
	{
		tokenArr[i] = token;
		token = strtok(NULL, SEP);
		i++;
	}
	tokenArr[i] = '\0';
	return (tokenArr);
}
