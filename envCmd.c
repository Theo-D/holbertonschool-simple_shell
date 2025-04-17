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

	if (environ == NULL)
		return (-1);

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
