#include "shell.h"
/**
 * _get_prompt - function to get the line typed
 * @info: Struct that contains general information
 * that goes through out all the program
 * Return: a pointer to a character
 *
 */
char *_get_prompt(info_t *info)
{
	size_t bufsize;
	int status;

	bufsize = 0;
	info->line = NULL;
	if (isatty(STDIN_FILENO) == 0)
		info->program_status = 1;

	else if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);



	if (getline(&info->line, &bufsize, stdin) == EOF)
	{
		free(info->line);
		status = info->error_status;
		if (isatty(STDIN_FILENO) == 1)
			write(1, "\n", 1);
		free(info);
		exit(status);
	}

	return (info->line);
}

