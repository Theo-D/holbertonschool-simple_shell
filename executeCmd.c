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
	pid_t errFork = 0;
	int  status = 0;

	if (av == NULL || av[0] == NULL)
	{
		/*fprintf(stderr, "Array of tokens is empty in executeCmd");*/
		freeArr(av);
		exit(4);
	}
	errFork = fork();
	if (errFork < 0)
	{
		freeArr(av);
		/*fprintf(stderr, "Child process was not created.");*/
		exit(4);
	}
	else if (errFork == 0)
	{
		/**
		 * fork should be successful here, we are inthe child process
		 * so we execute the file named after the command.
		 */
		if (execve(av[0], av, environ) == -1)
		{
			freeArr(av);
			/*fprintf(stderr, "Could not execute command");*/
			exit(0);
		}
	}
	else
	{
	/**
	 * If fork is successfull the following code will execute in the parent
	 * process, so we wait the child to terminate.
	 */
		wait(&status);
		/*equivalent to waitpid(errFork, &status, 0)*/
	}
	return (0);
}
