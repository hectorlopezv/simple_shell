#include "shell.h"

int main (__attribute__((unused)) int ac, char **argv)
{
	int c_number, status;
	char *buffer_line;
	size_t n_bytes_line;
	char **collection_string, *c_number_char, *path;
	int path_slash;

	path_slash = 0;
	buffer_line = NULL, collection_string = NULL, path = NULL;
	n_bytes_line = 0, c_number = 0, status = 0;
	signal(SIGINT, sig_handler);

	while(1)
	{
		c_number++;/*count line*/
		path_slash = 0;
		if(isatty(STDIN_FILENO) == 1)
			_prompt();
		if(getline(&buffer_line, &n_bytes_line, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			free(buffer_line);
			buffer_line = NULL;
			if(path != NULL){
				free(path);
				path = NULL;
			}
			if (collection_string != NULL){
				_free(collection_string);
				collection_string = NULL;
			}

			if(isatty(STDIN_FILENO) == 0){/* si es modo no it retorna ultimo commando del status del  hijo*/
				exit(status);
			}
			break;
		}

		if(buffer_line != NULL)
		{
			if (_is_empty(buffer_line) == 1)/* empty*/
				continue;

			collection_string = _tokenizer(buffer_line);
			if (collection_string[0] != NULL && collection_string != NULL)
				_builtin(collection_string[0], buffer_line, collection_string);
			path = _which(collection_string);/*mmm*/
			if (path == NULL)
			{
				if(_stat(collection_string[0]) == 0)
				{
					path_slash = 1;
					path = ft_strdup(collection_string[0]);
				}
			}

			if (path == NULL && path_slash == 0)
			{
				c_number_char = _convert(c_number, 10);
				write(STDERR_FILENO, argv[0], _strlen(argv[0]) );
				write(STDERR_FILENO, ": ", 2);
				write(STDERR_FILENO, c_number_char, _strlen(c_number_char));
				write(STDERR_FILENO, ": ", 2);
				write(STDERR_FILENO, collection_string[0],_strlen(collection_string[0]));
				write(STDERR_FILENO, ": not found\n", 12);
				status = 127;
				if (path != NULL)
					free(path);
				if (collection_string != NULL)
					_free(collection_string);
				path = NULL, collection_string = NULL;
				continue;
			}
			/* builtIn ,  path= -> cwd ,  PATH ->cwd->NULL*/
			status = _fork(path, collection_string);
			if (path != NULL)
				free(path);
			if (collection_string != NULL)
				_free(collection_string);
			path = NULL, collection_string = NULL;
		}/*IF*/
	}/*while*/
	return (0);
}/*main*/

