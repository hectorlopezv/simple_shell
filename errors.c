#include "shell.h"

int error_shell(int c_number, char **argv, char **colection_string)
{
	char *c_number_char;
	int status;

	status = 127;
	c_number_char = _convert(c_number, 10);
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, c_number_char, _strlen(c_number_char));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, colection_string[0], _strlen(colection_string[0]));
	write(STDERR_FILENO, ": not found\n", 12);/*127*/
	return (status);
}
