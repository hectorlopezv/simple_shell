#include "shell.h"
/**
 * _exec - execve implementation for Simple Shell.
 * @arguments: Arguments of the function.
 * @command: Array NULL terminated with the name of the command
 * @counter: Number of commands
 * Return: Always 0.
 */
int _exec(char **arguments, char **command, int counter)
{
	if (execve(command[1], arguments, environ) == -1)
	{
		_error(arguments, command, 1, counter);
	}
	return (0);
}

