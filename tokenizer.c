#include "shell.h"
/**
 * _tokenizer - split a string into a single word
 * @info: Struct that contains general information
 * that goes through out all the program
 * Return: A pointer to the separated pieces of whatever is received in getline
 */
char **_tokenizer(info_t *info)
{
	int i;
	char *piece;
	char **pieces;

	pieces = malloc(sizeof(char) * 1024);
	if (!pieces)
		return (pieces);

	piece = strtok(info->line, TOKEN_DELIMITERS);
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

