#include "shell.h"
/**
 * _get_prompt - function to get the line typed
 * Return: a pointer to a character
 *
 */
char *_get_prompt(void)
{
	char *buffer;
	size_t bufsize;

	bufsize = 0;
	buffer = NULL;
	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);

	if (getline(&buffer, &bufsize, stdin) == EOF)
	{
    if (isatty(STDIN_FILENO) == 1)
			write(STDIN_FILENO, "\n", 1);
		free(buffer);
    fflush(stdin);
		exit(EXIT_SUCCESS);
	}

	return (buffer);
}
