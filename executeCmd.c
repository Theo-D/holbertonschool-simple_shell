#include "shell.h"
/**
 * executeCmd - Handles creation of child process to execute function
 * input by user.
 * @av: array of string reprensenting command input by user.
 *
 * Return: 0 on succes, -1 on failure.
 */
int executeCmd(char **av)
{
	/*extern int exitStat;*/
	pid_t errFork = 0;
	int  status = 0;

	errFork = fork();
	if (errFork < 0)
	{
		/*fprintf(stderr, "Child process was not created.");*/;
		return (-1);
	}
	else if (errFork == 0)
	{
		/**
		 * fork should be successful here, we are in the child process
		 * so we execute the file named after the command.
		 */
		if (execve(av[0], av, environ) == -1)
		{
			/*fprintf(stderr, "Could not execute command");*/
			freeArr(av);
			return(-1);
		}
	}
	else
	{
	/**
	 * If fork is successfull the following code will execute in the parent
	 * process, so we wait the child to terminate.
	 */
		wait(&status);
		WEXITSTATUS(status);
	}
	return (0);
}
