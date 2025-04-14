#include "shell.h"
/**
 *
 */
void getCmd(char **av)
{
	int i = 0;
	cmd_t cmdFunc[] = {
		{"exit", exitCmd},
		{"env", envCmd},
		{NULL}
	};

	while (cmdFunc[i].cmd != NULL)
	{
		if (cmdFunc[i].cmd == av[0])
			cmdFunc[i].fun(av);
		else
		{
			printf("Error: Command not found");
			return;
		}
		i++;
	}
}
