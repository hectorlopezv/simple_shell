#include "shell.h"


char *_getenv(char *name)
{

	size_t  i;
	char *p;
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, 4) == 0)
		{
			p = environ[i];
			return (p);
		}

	}
	return (NULL);
}
void _prompt(void)
{
	write(STDIN_FILENO, "$ ", 2);
}

void sig_handler(__attribute__((unused))int num)
{

	write(1, "\n", 1);
	_prompt();

}
