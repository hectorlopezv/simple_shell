#include "shell.h"
/**
 * _error - handle errors of the program
 * @info: Struct that contains general information
 * that goes through out all the program
 * Return: The error integer or 0 in any other case
 */
int _error(info_t *info)
{
	int i;
	char *count_char;

	errors_t errors[] = {
		{1, ""},
		{2, "Misuse of shell builtins (according to Bash documentation)"},
		{3, "Command invoked cannot execute"},
		{127, ": not found\n"},
		{128, "Invalid argument to exit"},
		{130, "Script terminated by Control-C"},
		{290, ""},
		{0, NULL}
	};
	count_char = _convert(info->arguments_count, 10);

	if (info->error_status == 1)
	{
		perror("");
		exit(1);
	}

	for (i = 0 ; errors[i].status != 0 ; i++)
	{
		if (info->error_status == errors[i].status)
		{
			write(STDERR_FILENO, info->arguments[0], _strlen(info->arguments[0]) - 1);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, count_char, _strlen(count_char - 1)-1);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, info->tokenized[0], _strlen(info->tokenized[0]) - 1);
			write(STDERR_FILENO, errors[i].message, _strlen(errors[i].message) - 1);
		}
	}
	return (0);
}

