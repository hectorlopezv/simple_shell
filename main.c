#include "shell.h"
/**
 * main - Entry point
 * @av: Arguments of the stdin
 * @ac: Number of arguments
 * Return: EXIT_SUCCESS
 */
int main(int ac, char **av)
{
	_loop(ac, av);

	return (EXIT_SUCCESS);
}
