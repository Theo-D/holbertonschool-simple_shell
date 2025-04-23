#include "shell.h"

/**
 * main - Loops waiting for user input, until process is exited.
 *
 * Return: 0.
 */
int main(void)
{
	int exitStat = 0;

	while (1)
	{
		char *cmd;
		char **av;

		cmd = _getLine();
		av = tokenizeInput(cmd);
		getCmd(av, &exitStat);
		freeArr(av);
	}
	return (exitStat);
}
