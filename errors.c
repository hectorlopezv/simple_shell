#include "shell.h"

/**
 *error_shell - error_shell for exit status
 *@c_number: number of words
 *@argv: number of arguments passed CL
 *@colection_string: commands
 *@status: status of exit
 *Return: return the error status
 */
int error_shell(int c_number, char **argv, char **colection_string, int status)
{
	char *c_number_char;

	if (status == 127)
	{
		c_number_char = _convert(c_number, 10);
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, c_number_char, _strlen(c_number_char));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, colection_string[0], _strlen(colection_string[0]));
		write(STDERR_FILENO, ": not found\n", 12);/*127*/
	}

	if (status == 2)
	{
		/*	sh: 1: exit: Illegal number: HTBN*/
		c_number_char = _convert(c_number, 10);
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, c_number_char, _strlen(c_number_char));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, colection_string[0], _strlen(colection_string[0]));
		write(STDERR_FILENO, ": Illegal number: ", _strlen(": Illegal number: "));
		write(STDERR_FILENO, colection_string[1], _strlen(colection_string[1]));
		write(STDERR_FILENO, "\n", 1);
	}
	return (status);
}
