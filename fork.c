#include "shell.h"

int _fork(char *path, char **commands)
{
	int status;
	pid_t c_pid, pid;

	c_pid = fork();
	if (c_pid == 0)/*child*/
	{
		if (execve(path, commands , environ) == -1)
		{
			free(path);
			free(commands);
			status = 127;
			exit(127);/* permissin denied*/
		}
		/*estamos ene l hijo*/
	}
	else if (c_pid > 0)
	{
		pid = wait(&status);
		if (pid < 0)/*error*/
			exit(EXIT_FAILURE);
		if (WIFEXITED(status) == 1)/*EXIT normaly*/
			status = WEXITSTATUS(status);
		return (status);
	}
	else{

		exit(EXIT_FAILURE);
	}
	return(-1);/*error on fork look errno*/
}
