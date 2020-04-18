#include "shell.h"
/**
 * _loop - execve implementation for Simple Shell.
 * @av: Arguments of the function.
 * @ac: Number of arguments
 * Return: Nothing.
 */
void _loop(int ac, char **av)
{

	char *line;
	char **parsed;
	int exec, c_count;

	c_count = 0;
	while (STATUS)
	{

		signal(SIGINT, _signals);
		line = _get_prompt();
		if (!line)
			_error(NULL, av, 290, c_count);

		if (line[0] == '\n')
		{
			fflush(stdin);
			c_count += 1;
			free(line);
			continue;
		}
		parsed = _split_string(line);

		if (!parsed)
			_error(NULL, av, 2, c_count);

		if (parsed[0] != 0)
			_builtin(parsed, ac);

		c_count += 1;
		exec = _fork(parsed, av, ac, c_count);
		if (exec == -1)
			_error(NULL, av, 1, c_count);

		free(parsed);
		free(line);
	}
}
