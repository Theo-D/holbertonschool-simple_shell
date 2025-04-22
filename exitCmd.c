#include "shell.h"
/**
 * exitCmd - Exits current process.
 * @av: Array of strings.
 * @exitStat: integer to follow the value of exit status.
 *
 * Return: 0 on success.
 */
int exitCmd(char **av, int *exitStat)
{
	printf("Valeur de exitStat dans exitCmd: %d\n", *exitStat);
	freeArr(av);
	exit(*exitStat);
}
