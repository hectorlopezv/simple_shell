#include "shell.h"
/**
 * _fork - creates a new process from the parent
 * @info: Struct that contains general information
 * that goes through out all the program
 * Return: 0 on sucess, 1 on failure.
 */
int _fork(info_t *info)
{
	int status;
	pid_t c_pid, pid;

	c_pid = fork();
	if (c_pid == 0)
	{
		info->command = _which(info);
		if (info->command != NULL)
		{
			if (_exec(info) == -1)
			{
				info->error_status = 126;
				status = info->error_status;
				_error(info);
				free(info);
				exit(status);
			}
		}
		info->error_status = 127;
		status = info->error_status;
		_error(info);
		_free(info);
		free(info);
		exit(status);
	}
	else if (c_pid > 0)
	{
		pid = wait(&status);
		if (pid < 0)
			exit(EXIT_FAILURE);
		if (WIFEXITED(status))
			info->error_status = WEXITSTATUS(status);

		wait(NULL);
	}
	else
		exit(EXIT_FAILURE);

	return (0);
}

