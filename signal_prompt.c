#include "shell.h"

/**
 *_getenv - obtan env variable
 *@name: name of the env variable to search
 *Return: the path env variable
 */
char *_getenv(char *name)
{

	size_t  i;
	char *p;
	if (environ != NULL)
	{
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
	return (NULL);
}

/**
 *_prompt - print prompt
 *Return: return nothing
 */

void _prompt(void)
{
	write(STDIN_FILENO, "> ", 2);
}

/**
 *sig_handler - handles signal for shell
 *@num: # of signal
 *Return: nothing
 */

void sig_handler(__attribute__((unused)) int num)
{

	write(1, "\n", 1);
	_prompt();

}
