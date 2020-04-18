#include "shell.h"
/**
 *main - main program
 *@ac: number of argumets for argv
 *@argv: number of strings passed in CL
 *Return: return 0
 */

int main(__attribute__((unused)) int ac, char **argv)
{
	int c_number, status;
	size_t n_bytes_line;
	char **collection_string, *path, *buffer_line;

	buffer_line = NULL, collection_string = NULL, path = NULL;
	n_bytes_line = 0, c_number = 0, status = 0, signal(SIGINT, sig_handler);
	while (1)
	{
		c_number++;
		if (isatty(STDIN_FILENO) == 1)
			_prompt();
		if (getline(&buffer_line, &n_bytes_line, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			free(buffer_line), buffer_line = NULL, _free_2(&collection_string, &path);
			if (isatty(STDIN_FILENO) == 0)/*iteractive mode*/
				exit(status);
			exit(status);
		}
		if (buffer_line != NULL)
		{
			if (_is_empty(buffer_line) == 1)/* empty*/
				continue;
			collection_string = _tokenizer(buffer_line);
			if (check_for_built_in(&collection_string, &buffer_line, &status, argv, c_number) == 0)
				continue;/* builtin*/
			path = _which(collection_string);/*malloc - check path*/
			if (path == NULL)
			{
				status = error_shell(c_number, argv, collection_string, 127);
				_free_2(&collection_string, &path);
				continue;
			}
		}
		status = _fork(&path, &collection_string);/*fork to execute command */
		_free_2(&collection_string, &path);/*free malloc strings */
	}
	return (0);
}

