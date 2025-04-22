#include "shell.h"
/**
 * exitCmd - Exits current process.
 * @av: Array of strings.
 * @exitStat: integer to follow the value of exit status.
 *
 * Return: 0 on success.
 */
int exitCmd(char **av, int exitStat)
{
	freeArr(av);
	exit(exitStat);
}
