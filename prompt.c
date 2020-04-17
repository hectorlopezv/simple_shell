#include <ctype.h>
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

	if (_is_empty(info->line) == 1)
	{
		free(info->line);
		info->line = NULL;
		status = info->error_status;
		if (isatty(STDIN_FILENO) == 0)
			write(1, "\n", 1);
		return (info->line);
	}
	return (info->line);
}
/**
 * _is_empty - function to check if the command is only white spaces
 * @s: Character to be checked on
 *
 * Return: 0 if any character is not whitespace (i.e. line is not empty),
 * or 1 otherwise
 *
 */

int _is_empty(const char *s)
{
	while (*s != '\0')
	{
		if (!_isspace((unsigned char)*s))
			return (0);
		s++;
	}
	return (1);
}

/**
 * _isspace - Function that compares c to check if it is one of the cases
 * @c: Character to be checked on
 *
 * Return: 0 if any character is one of the cases,
 * or 1 otherwise
 *
 */
int _isspace(int c)
{
	return (c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

