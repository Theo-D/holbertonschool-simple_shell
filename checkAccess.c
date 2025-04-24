#include "shell.h"
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
