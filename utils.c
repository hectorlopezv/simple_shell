#include "shell.h"


/**
 *_free - free 2d array¬
 *@parsed_buffer: 2d array¬
 *Return: nothing¬
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
 *@status: error status
 *@argv: arguments
 *@c_number: c_number
 *Return: return -1 if failt
 */
int _builtin(char *builtIn, char **buffer_line, char ***collection_string,
		int *status, char **argv, int c_number)
{
	int i;
	char *target;

	if (_strcmp(builtIn, "exit") == 0)
	{
		if ((*collection_string)[1] != NULL)
		{
			target = (*collection_string)[1];
			for (i = 0; target[i] != 0; i++)
			{
				if (target[i] < '0' || target[i] > '9')
				{
					*status = error_shell(c_number, argv, *collection_string, 2);
					_free_2(collection_string, buffer_line);
					return (0);
				}
			}
			*status = _atoi((*collection_string)[1]);
			if (*status < 0)
			{
				*status = error_shell(c_number, argv, *collection_string, 2);
				_free_2(collection_string, buffer_line);
				return (0);
			}
			_free_2(collection_string, buffer_line), exit(*status);
		}
		_free_2(collection_string, buffer_line), exit(*status);
	}
	if (_strcmp(builtIn, "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		_free_2(collection_string, buffer_line);
		return (0);
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



/**
 *_free_2 - free 2d array
 *@parsed_buffer: 2d array
 *@path: path to clean
 *Return: nothing
 */
void _free_2(char ***parsed_buffer, char **path)
{
	if (*path != NULL)
		free(*path);
	if (*parsed_buffer != NULL)
		_free(*parsed_buffer);
	*path = NULL, *parsed_buffer = NULL;
}
