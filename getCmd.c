#include "shell.h"
/**
 * getCmd - Compares first argument of av and executes corresponding
 * builtin if it exists. Otherwise calls executeCmd.
 * @av: Array of strings representing user input command.
 * @exitStat: integer to follow the value of exit status.
 *
 * Return: Nothing.
 */
void getCmd(char **av, int *exitStat)
{
	int i = 0, errFun = 0;
	cmd_t cmdFunc[] = {
		{"env", envCmd},
		{"exit", exitCmd},
		{NULL}
	};

	if (av == NULL || av[0] == NULL)
		return;

	while (cmdFunc[i].cmd != NULL)
	{
		if (strcmp(cmdFunc[i].cmd, av[0]) == 0)
		{
			cmdFunc[i].fun(av, 0);
			return;
		}
		i++;
	}
	errFun = -1;

	errFun = executeCmd(av, exitStat);
	/*printf("%d\n", *exitStat);*/

	if (errFun == -1)
	{

		exitCmd(av, *exitStat);
	}
}
