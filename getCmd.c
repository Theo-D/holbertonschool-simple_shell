#include "shell.h"
/**
 * getCmd - Compares first argument of av and executes corresponding
 * builtin if it exists. Otherwise calls executeCmd.
 * @av: Array of strings representing user input command.
 *
 * Return: Nothing.
 */
void getCmd(char **av)
{
	int i = 0;
	cmd_t cmdFunc[] = {
		{"env", envCmd},
		{"exit", exitCmd},
		{NULL}
	};

	if (av == NULL || av[0] == NULL)
	{
		/*frpintf(stderr, "Array of tokens is empty in getCmd");*/
		free(av);
		exit(-1);
	}

	while (cmdFunc[i].cmd != NULL)
	{
		if (strcmp(cmdFunc[i].cmd, av[0]) == 0)
		{
			cmdFunc[i].fun(av);
			return;
		}
		i++;
	}

	executeCmd(av);
}
