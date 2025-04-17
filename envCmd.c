#include "shell.h"
/**
 * envCmd - Prints array of environment variables.
 * @av: Array of strings.
 *
 * Return: 0 on succes, -1 on failure
 */
int envCmd(__attribute__((unused))char **av)
{
	int i = 0;
	char **envCpy = environ;

	if (envCpy == NULL)
		return (-1);

	while (envCpy[i])
	{
		printf("%s\n", envCpy[i]);
		i++;
	}
	return (0);
}
