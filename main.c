#include "shell.h"

/**
 * main - Loops waiting for user input, until process is exited.
 *
 * Return: 0.
 */
/*tester avec int argc, char ** argv*/
int main(void)
{
	int exitStat = 0;

	while (1)
	{
		char *cmd;
		char **av;

		cmd = _getLine();
		av = tokenizeInput(cmd);
<<<<<<< HEAD
		getCmd(av);
=======
		getCmd(av, &exitStat);
>>>>>>> origin/main
		freeArr(av);
	}
	return (exitStat);
}
