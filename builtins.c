#include "shell.h"
/**
 * _builtin - Builtin function exit for simple_shell.
 * @arguments: Arguments of the function.
 * @ac: Number of arguments
 * Return: Always 0.
 */
int _builtin(char **arguments, int ac)
{

	if (strcmp(arguments[0], "exit") == 0)
	{
		_free(arguments, ac);
		exit(EXIT_SUCCESS);
	}

	return (-1);
}
