#include "shell.h"
/**
 * _which - Find the directory needed
 * @info: Struct that contains general information
 * that goes through out all the program
 *
 * Return: A character pointer with the command found in
 * the path or NULL otherwise.
 */
char *_which(info_t *info)
{
	char *aux, *path, *check_path;
	int size;

	size = _strlen(info->tokenized[0]);
	if (!info->tokenized)
		return (NULL);

	path = strtok(_getenv("PATH"), TOKEN_DELIMITERS);
	check_path = _check_cwd(path, info);
	if (check_path != NULL)
		return (check_path);
	while (path != NULL)
	{
		aux = malloc(_strlen(path) + size + 1);
		if (!aux)
			return (aux);
		aux = _strcpy(aux, path);
		aux = _strcat(aux, "/");
		aux = _strcat(aux, info->tokenized[0]);
		if (_stat(aux) == 0)
			return (aux);
		path = strtok(NULL, TOKEN_DELIMITERS);
		free(aux);
	}
	if (_stat(info->tokenized[0]) == 0)
		return (info->tokenized[0]);
	return (NULL);
}

/**
 * _check_cwd - Check current folder
 * @info: Struct that contains general information
 * that goes through out all the program
 * @path: Path of the environ variable
 * Return: pointer string with found path or NULL in failure.
 */
char *_check_cwd(char *path, info_t *info)
{
	if (path[5] == '\0')
	{
		if (_stat(info->tokenized[0]) == 0)
			return (info->tokenized[0]);
	}
	return (NULL);
}

