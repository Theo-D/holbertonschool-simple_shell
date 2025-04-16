#include "shell.h"
/**
 *
 */
void getCmd(char **av)
{
	int i = 0, errCmd = 0;
	cmd_t cmdFunc[] = {
		{"env", envCmd},
		{"exit", exitCmd},
		{NULL}
	};
	while (cmdFunc[i].cmd != NULL)
	{
		if ((errCmd = strcmp(cmdFunc[i].cmd, av[0])) == 0)
		{
			cmdFunc[i].fun(av);
			break;
		}
		i++;
	}
	/*printf("errCmd en sortie de boucle: %d\n", errCmd);*/
	executeCmd(av);
	/*printf("errCmd après executeCmd: %d\n", errCmd);*/
	if (errCmd < 0)
		printf("%s: Command not found\n", av[0]);
}
