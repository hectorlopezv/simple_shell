#include "shell.h"
/**
 * _builtin - Builtin function exit for simple_shell.
 * @info: Structure that contains the general
 * information of all the program.
 *
 * Return: -1 if the tokenized word is "exit" and
 * EXIT_SUCCESS if the string is "exit".
 */
int _builtin(info_t *info)
{
	if (_strcmp(info->tokenized[0], "exit") == 0)
	{
		_free(info);

		free(info);
		exit(EXIT_SUCCESS);
	}

	return (-1);
}
