#include "shell.h"
/**
 * _signals - handle errors of the program
 * @signal: integer that indicates the SIGINT signal.
 *
 * Return: Nothing
 */
void _signals(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "I won't die..", 13);
		sleep(1);
		write(STDOUT_FILENO, "Just kidding\n", 12);
	}
}
