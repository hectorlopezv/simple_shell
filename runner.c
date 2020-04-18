#include "shell.h"

int main(__attribute__((unused)) int ac, char **argv)
{
	int c_number, status, path_slash, built_flag;
	size_t n_bytes_line;
	char **collection_string, *path, *buffer_line;

	buffer_line = NULL, collection_string = NULL, path = NULL;
	n_bytes_line = 0, c_number = 0, path_slash = 0;
	signal(SIGINT, sig_handler);

	while (1)
	{
		c_number++, path_slash = 0;
		if (isatty(STDIN_FILENO) == 1)
			_prompt();
		if (getline(&buffer_line, &n_bytes_line, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			free(buffer_line), buffer_line = NULL;
			_free_2(&collection_string, &path);
			if (isatty(STDIN_FILENO) == 0){/*iteractive mode*/
				exit(status);
			}
			exit(status);
		}
		if (buffer_line != NULL)
		{
			if (_is_empty(buffer_line) == 1)/* empty*/
				continue;
			collection_string = _tokenizer(buffer_line);
			if (collection_string[0] != NULL && collection_string != NULL)
			{
				built_flag = _builtin(collection_string[0], &buffer_line, &collection_string);
				if (built_flag != -1)
					continue;
			}
			path = _which(collection_string);/*mmm*/
			if (path == NULL)
				if (_stat(collection_string[0]) == 0)
					path_slash = 1, path = ft_strdup(collection_string[0]);
			if (path == NULL && path_slash == 0)
			{
				status = error_shell(c_number, argv, collection_string);
				_free_2(&collection_string, &path);
				continue;
			}
			status = _fork(&path, &collection_string);
			_free_2(&collection_string, &path);
		}
	}
	return (0);
}

