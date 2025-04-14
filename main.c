#include "shell.h"
/**
 *
 */
/*tester avec int argc, char ** argv*/
int main(void)
{
	while(1)
	{
		char *cmd;
		char **av;

		cmd = _getLine();
		av = tokenizeInput(cmd);
		getCmd(av);
		free(cmd);
	}
	return (0);
}
