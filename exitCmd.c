#include "shell.h"
/**
 * exitCmd - Exits current process.
 * @av: Array of strings.
 *
 * Return: 0 on success.
 */
int exitCmd(__attribute__((unused))char **av)
{
	exit(EXIT_FAILURE);
	return (0);
}
