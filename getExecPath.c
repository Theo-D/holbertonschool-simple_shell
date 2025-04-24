#include "shell.h"
/**
 * getExecPath - Looks for executable file by searching through a list of paths
 * and matching it with its command name.
 * @pathArr: List of paths to be searched through.
 * @cmd: command name to be matched with executable file name.
 *
 * Return: String of the complete pathname to the executable.
 */
char *getExecPath(char **pathArr, char *cmd)
{
	int i = 0;
	char *fullPath;
	char *cmdToAppend = malloc((strlen(cmd) * sizeof(char)) + 2);

	if (cmdToAppend == NULL || *pathArr == NULL)
	{
		free(cmdToAppend);
		freeArr(pathArr);
		exit(2);
	}
	strcpy(cmdToAppend, "/");
	strcat(cmdToAppend, cmd);
	while (*pathArr != NULL)
	{
		fullPath = malloc((strlen(pathArr[i]) * sizeof(char)) +
				(strlen(cmdToAppend) + 1));
		if (fullPath == NULL)
		{
			free(fullPath);
			free(cmdToAppend);
			exit(2);
		}
		strcpy(fullPath, pathArr[i]);
		strcat(fullPath, cmdToAppend);
		if (access(fullPath, F_OK) == 0)
			break;
		free(fullPath);
		fullPath = NULL;
		i++;
	}
	if (fullPath == NULL)
	{
		free(cmdToAppend);
		freeArr(pathArr);
		return (NULL);
	}
	free(cmdToAppend);
	freeArr(pathArr);

	return (fullPath);
}
