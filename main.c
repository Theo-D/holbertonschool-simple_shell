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
		int errTrack = 0;

		cmd = _getLine();
		av = tokenizeInput(cmd);
		errTrack = getCmd(av, &exitStat);
		freeArr(av);
		exitHandler(errTrack);
	}
	return (exitStat);
}
