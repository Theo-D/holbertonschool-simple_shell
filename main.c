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

		cmd = _getLine();
		tokenizeInput(cmd);


		free(cmd);
	}
	return (0);
}
