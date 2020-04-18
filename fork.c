#include "shell.h"
/**
 * _fork - creates a new process from the parent
 * @info: Struct that contains general information
 * Return: 0 on sucess, 1 on failure.
 */
int _fork(info_t *info)
{
	int status;
	pid_t c_pid, pid;

	_is_executable(info);
	if (info->execution == 1)
	{	c_pid = fork();
		if (c_pid == 0)
		{
			info->command = _which(info);
			if (info->command != NULL)
			{
				if (_exec(info) == -1)
				{	info->error_status = 126;
					status = info->error_status;
					_clean_up(info, 1);
					exit(status);
				}
			}
			info->error_status = 127;
			status = info->error_status;
			_clean_up(info, 1);
			exit(status);
		}
		else if (c_pid > 0)
		{	pid = wait(&status);
			if (pid < 0)
				exit(EXIT_FAILURE);
			if (WIFEXITED(status) == 1)
				info->error_status = WEXITSTATUS(status);

			return (info->error_status);
		}
		else
			exit(EXIT_FAILURE);
	}
  
	info->error_status = 127;
	status = info->error_status;
	_error(info);
	return (status);
}

/**
 * _clean_up - Function to make some child proccess clean up
 * @info: Struct that contains general info
 * @selector: Clean up mode
 *
 */
void _clean_up(info_t *info, int selector)
{
	if (selector == 1)
	{
		_error(info);
		free(info);
	}
	_error(info);
	_free(info);
	free(info);
}
