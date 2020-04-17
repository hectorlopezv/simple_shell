#include "shell.h"
/**
 * _fork - creates a new process from the parent
 * @arguments: arguments received.
 * @command: Array that contains the name of the argument
 * @ac: Arguments count
 * @count: Number of commands for the error
 * Return: 0 on sucess, 1 on failure.
 */
int _fork(char **arguments, char **command, int ac, int count)
{
	pid_t c_pid, pid;
	int status;

	c_pid = fork();

	if (c_pid == 0)
	{
		command[1] = _which(arguments);

		if (command[1] != NULL)
		{
			_exec(arguments, command, count);
		}
		_error(arguments, command, 1, count);
		_free(arguments, ac);
		exit(EXIT_FAILURE);
	}
	else if (c_pid > 0)
	{
		pid = wait(&status);
		if (pid < 0)
			exit(EXIT_FAILURE);

		wait(NULL);
	}
	else
		exit(EXIT_FAILURE);

	return (0);
}

