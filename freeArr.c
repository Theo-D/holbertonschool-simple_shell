#include "shell.h"
/**
 * freeArr - Frees array of string.
 * @av: Array to be freed.
 *
 * Return: Nothing
 */
void freeArr(char **av)
{
	int i = 0;

	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
