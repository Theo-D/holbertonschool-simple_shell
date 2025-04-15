#include "shell.h"
/**
 *
 */
void getCmd(char **av)
{
	int i = 0;
	cmd_t cmdFunc[] = {
		{"env", envCmd},
		{"exit", exitCmd},
		{NULL}
	};

	while (cmdFunc[i].cmd != NULL)
	{
		if (strcmp(cmdFunc[i].cmd, av[0]) == 0)
		{
			cmdFunc[i].fun(av);
			return;
		}

		/*Implement command not found handling*/
		/*else
			printf("ERRROR: Command not found");*/
		i++;
	}
}
