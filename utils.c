#include "shell.h"
/**
 * _strlen - Returns the length of a string.
 * @str: The string to get the length of.
 *
 * Return: The length of @str.
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (*str++)
		length++;

	return (length + 1);
}
/**
 * _strcat - concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: pointer
 */
char *_strcat(char *dest, const char *src)
{
	size_t i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}

/**
 * _strcpy - Function that copies the string pointed to by src, including the
 * terminating null byte (\0), to the buffer pointed to by dest.
 * @src: Pointer of source
 * @dest: Pointer of destiny
 * Return: Char destiny of the str copied
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
		if (src[i] == '\0')
		{
			dest[i] = '\0';
		}
	}
	return (dest);
}

/**
 * _strncmp - Compare the first n letters of two strings
 * @s1: string
 * @s2: string
 * @size: Character size
 * Return: negative int if s1 < s2, 0 if matching, and positive int if s1 > s2
 */

int _strncmp(char *s1, const char *s2, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

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

