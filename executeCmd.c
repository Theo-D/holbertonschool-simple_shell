#include "shell.h"
/**
 *
 */
int executeCmd(char **av)
{
	pid_t errFork = 0;
	int errExec = 0, status = 0;

	errFork = fork();
	
	if (errFork < 0)
	{
		/*HANDLE ERROR*/
		exit(-1);
	}
	else if (errFork == 0)
	{
		/**
		 * fork should be successful here, we are inthe child process
		 * so we execute the file named after the command.
		 */
		errExec = execve(av[0], av, environ);
		if(errExec)
		{
			/*HANDLE ERROR*/
			exit(-1);
		}
	}
	/**
	 * If fork is successfull the following code will execute in the parent
	 * process, so we wait the child to terminate.
	 */
	wait(&status);
	/*equivalent to waitpid(-1, &status, 0)*/
	return (0);
}
