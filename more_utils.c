#include "shell.h"
/**
 * _strcmp - Compare two strings
 * @s1: string
 * @s2: string
 * Return: negative int if s1 < s2, 0 if matching, and positive int if s1 > s2
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

	}
	return (0);
}

/**
 * _convert - print_str
 * @num: buffer
 * @base: base to be converted
 * Return: Pointer to a character
 */
char *_convert(long int num, int base)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long   n;

	array = "0123456789abcdef";
	n = num;
	if (num < 0)
	{
		n = -num;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';
	do      {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
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
		aux = malloc(_strlen(path) + size + 1);
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
	char *path, *aux, env[300];
	int size;

	size = _strlen(info->tokenized[0]);
	if (!info->tokenized)
		return;

	if (_stat(info->tokenized[0]) == 0)
	{
		info->execution = 1;
		return;
	}
	_strcpy(env, _getenv("PATH"));
	path = strtok(env, TOKEN_DELIMITERS);
	while (path != NULL)
	{
		aux = malloc(_strlen(path) + size + 1);
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

/**
 * _strdup - Pointer to a newly allocated space in memory
 *
 * @str: String to copy
 *
 * Return: String copied
 **/
char *_strdup(char *str)
{
	int size, i;
	char *dest;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(dest + i) = *(str + i);

	/* (dest + i) = 0; */

	return (dest);
}

