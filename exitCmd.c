#include "shell.h"
/**
 * exitCmd - Exits current process.
 * @av: Array of strings.
 *
 * Return: 0 on success.
 */
int exitCmd(char **av/*, int exitStat*/)
{
	freeArr(av);
	exit(0);
}
