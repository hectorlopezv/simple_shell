#include "shell.h"

/**
 *_fork - fork
 *@path: bin/ls
 *@commands: ["ls","-l","NULL"]
 *Return: return status error from child
 */

int _fork(char **path, char ***commands)
{
	int status;
	pid_t c_pid, pid;
	c_pid = fork();
	if (c_pid == 0)/*child*/
	{
		if (execve(*path, *commands, environ) == -1)
		{
			fflush(stdin);
			_free_2(commands, path);
			status = 127;
			exit(127);/* permissin denied*/
		}
		/*estamos ene l hijo*/
	}
	else if (c_pid > 0)
	{
		fflush(stdin);
		pid = wait(&status);
		if (pid < 0)/*error*/
			exit(EXIT_FAILURE);
		if (WIFEXITED(status) == 1)/*EXIT normaly*/
			status = WEXITSTATUS(status);
		return (status);
	}
	else
	{

		exit(EXIT_FAILURE);
	}
	return (-1);/*error on fork look errno*/
}
