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
 *_strdup - dump
 * @str: string literal
 *Return: return string
 */

char *_strdup(char *str)
{
	int i, j;
	char *C;

	if (str == NULL)
	{
		return (NULL);
	}


	for (j = 0; str[j] != '\0'; j++)
	{

	}

	C = (char *) malloc(j + 1);

	if (C == NULL)
	{
		return (NULL);

	}

	for (i = 0; i < j; i++)
	{
		C[i] = str[i];
	}

	C[i] = str[i];

	return (C);
}

