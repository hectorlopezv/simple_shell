#include "shell.h"
/**
 * _getenv - looks for the path
 * @name: variable to be look
 * Return: a pointer to a string
 */
char *_getenv(const char *name)
{
	char **env;
	size_t  i;
	char *p;

	env = environ;
	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], name, 4) == 0)
		{
			p = env[i];
			return (p);
		}

	}
	return (NULL);
}

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
	char *path, *aux, env[300];
	int size;

	size = _strlen(info->tokenized[0]);

	if (!info->tokenized)
		return (NULL);
	_strcpy(env, _getenv("PATH"));
	path = strtok(env, TOKEN_DELIMITERS);
	while (path != NULL)
	{
		aux = malloc(_strlen(path) + size );
		if (!aux)
			return (NULL);
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
 * _is_executable - Find out if the give path is executable
 * @info: Struct that contains general information
 * that goes through out all the program
 *
 */

void _is_executable(info_t *info)
{
	char *path, *aux, env[512];
	int size;

	size = _strlen(info->tokenized[0]);
	if (info->tokenized == NULL)
		return;

	if (_stat(info->tokenized[0]) == 0)
	{
		info->execution = 1;
		return;
	}
	_strcpy(env, _getenv("PATH"));
	path = strtok(env, TOKEN_DELIMITERS);
	while (path != NULL)
	{/* l s o l \0*/    /* / \0*/ 2  /*h e c \0 */    /*h e c / l s o l \0*/
		aux = malloc(_strlen(path) + size);  
		if (!aux)
			return;

		aux = _strcpy(aux, path);
		aux = _strcat(aux, "/");
		aux = _strcat(aux, info->tokenized[0]);
		if (_stat(aux) == 0)
			info->execution = 1;

		path = strtok(NULL, TOKEN_DELIMITERS);
		free(aux);
	}
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
	if (path[0] == ':')
	{
		if (_stat(info->tokenized[0]) == 0)
			return (info->tokenized[0]);
	}
	return (NULL);
}
