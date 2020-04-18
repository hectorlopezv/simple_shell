#include "shell.h"

/**
 *_free - free 2d array
 *@parsed_buffer: 2d array
 *Return: nothing
 */
void _free(char **parsed_buffer)
{
	int i;

	for (i = 0; parsed_buffer[i] != NULL; i++)
		free(parsed_buffer[i]);

	free(parsed_buffer);

}

/**
 *_builtin -  builtIns
 *@builtIn: built in to look
 *@buffer_line: buffer_line to free
 *@collection_string: array of commands
 *Return: return -1 if failt
 */
int _builtin(char *builtIn, char *buffer_line, char **collection_string)
{
	if (_strcmp(builtIn, "exit") == 0)
	{
		free(buffer_line);
		if (collection_string != NULL)
			_free(collection_string);
		exit(EXIT_SUCCESS);
	}
	return (-1);
}

/**
 *_is_empty - check if string has TOKEN_DELIMITERs
 *@s: string to be evaluated
 *Return: return 0 if match found 1 otherwise
 */
int _is_empty(const char *s)
{
	while (*s != '\0')
	{
		if (_isspace((unsigned char)*s) == 0)
			return (0);
		s++;
	}
	return (1);
}

/**
 *_isspace - Function that compares c to check if it is one of the cases
 * @c: Character to be checked on
 *Return: 0 if any character is one of the cases,
 * or 1 otherwise
 */
int _isspace(int c)
{
	return (c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

