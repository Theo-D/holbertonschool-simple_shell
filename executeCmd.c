#include "shell.h"
/**
 * executeCmd - Handles creation of child process to execute function
 * input by user.
 * @av: array of string reprensenting command input by user.
 * @exitStat: integer to follow the value of exit status.
 *
 * Return: 0 on succes, -1 on failure.
 */
int executeCmd(char **av, int *exitStat)
{
	pid_t pidFork = 0;
	int  status = 0;
	char **path = getPath();
	char *execPath = NULL;

	if (*path == NULL)
		return (-1);

	execPath = getExecPath(path, av[0]);

	if (execPath != NULL)
	{
		pidFork = fork();
		
		if (pidFork < 0)
		{
			return (-1);
		}
		else if (pidFork == 0)
		{
			/**
		 	* fork should be successful here, we are in the child process
		 	* so we execute the file named after the command.
		 	*/
			if (execve(execPath, av, environ) == -1)
			{
				freeArr(av);
				free(execPath);
				return (-1);
			}
		}
		else
		{
		/**
	 	* If fork is successfull the following code will execute in the parent
	 	* process, so we wait the child to terminate.
	 	*/
			wait(&status);
			*exitStat = WEXITSTATUS(status);
		}
		free(execPath);
		return (0);
	}
	else
	{
		freeArr(av);
		free(execPath);
		return (-1);
	}
}
