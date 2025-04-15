#include "shell.h"
/**
 *
 */
int envCmd( __attribute__((unused))char **av)
{
	int i = 0;

	if (environ == NULL)
		return (1);

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
