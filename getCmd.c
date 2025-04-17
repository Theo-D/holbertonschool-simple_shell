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
	int i = 0, errCmd = 0;
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
			break;
		}
		else
			errCmd = -1;
		i++;
	}
	/*fprintf(stderr, "errCmd en sortie de boucle: %d\n", errCmd);*/
	executeCmd(av);
	/*fprintf(stderr, "errCmd après executeCmd: %d\n", errCmd);*/
	if (errCmd < 0)
	{
		/*fprintf(stderr, "%s: Command not found\n", av[0]);*/
		free(*av);
		*av = NULL;
	}
}
