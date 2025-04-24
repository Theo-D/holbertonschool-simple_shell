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
	freeArr(av);
	exit(*exitStat);
}
/**
 * envCmd - Prints array of environment variables.
 * @av: Array of strings.
 * @exitStat: integer to follow the value of exit status.
 *
 * Return: 0 on succes, -1 on failure
 */
int envCmd(__attribute__((unused))char **av,
		__attribute__((unused))int *exitStat)
{
	int i = 0;
	char **envCpy;

	if (environ == NULL)
	{
		return (-1);
	}

	envCpy = environ;

	while (envCpy[i])
	{
		printf("%s\n", envCpy[i]);
		i++;
	}
	return (0);
}
