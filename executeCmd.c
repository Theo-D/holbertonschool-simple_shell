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
	int errExec = 0, status = 0;

	if (av == NULL)
	{
		exit(EXIT_FAILURE);
	}
	errFork = fork();

	if (errFork < 0)
	{
		perror("Child process was not created.");
		exit(-1);
	}
	else if (errFork == 0)
	{
		/**
		 * fork should be successful here, we are inthe child process
		 * so we execute the file named after the command.
		 */
		errExec = execve(av[0], av, environ);
		if (errExec)
		{
			perror("Could not execute command");
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
