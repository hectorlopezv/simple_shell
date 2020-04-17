#include "shell.h"
/**
 * _exec - execve implementation for Simple Shell.
 * @info: Struct that contains general information
 * that goes through out all the program
 *
 * Return: If the command is not executed returns -1 and 0 otherwise.
 */
int _exec(info_t *info)
{
	if (execve(info->command, info->tokenized, environ) == -1)
		return (-1);

	return (0);
}
