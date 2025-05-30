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
{	pid_t pidFork = 0;
	int  status = 0, errTrack = 0;
	char **path, *execPath = NULL;

	if (av[0][0] == '/' || av[0][0] == '.')
		execPath = strdup(av[0]);
	else
	{	path = getPath();
		execPath = getExecPath(path, av[0]);
		if (path == NULL || execPath == NULL)
		{	fprintf(stderr, "./hsh: 1: %s: not found\n", av[0]);
			return (-3);
		}
		path = NULL;
	}
	if (execPath != NULL)
	{	errTrack = checkAccess(execPath);
		if (errTrack < 0)
		{	free(execPath);
			return (errTrack);
		}
		pidFork = fork();
		if (pidFork < 0)
			return (-1);
		else if (pidFork == 0)
		{
			if (execve(execPath, av, environ) == -1)
			{	freeArr(av);
				free(execPath);
				return (-1);
			}
		}
		else
		{	wait(&status);
			*exitStat = WEXITSTATUS(status);
		}
		free(execPath);
		return (0);
	}
	else
	{	freeArr(av);
		free(execPath);
		return (-1);
	}
}
