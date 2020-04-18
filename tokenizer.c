#include "shell.h"
/**
 * _split_string - split a string into a single word
 * @line: line to be separated
 * Return: a pointer that keeps a vector of pointers
 */
char **_split_string(char *line)
{
	int i;
	char *piece;
	char **pieces;

	pieces = malloc(sizeof(char) * 1024);
	if (!pieces)
		return (pieces);

	piece = strtok(line, TOKEN_DELIMITERS);
	i = 0;
	while (piece != NULL)
	{
		pieces[i] = piece;
		i++;
		piece = strtok(NULL, TOKEN_DELIMITERS);
	}
	pieces[i] = NULL;

	return (pieces);
}

