#include "shell.h"
/**
 *_strcpy - copy src to dest
 *@dest: destiny
 *@src: source string
 *Return: return pointer to new string
 */
char *_strcpy(char *dest, char *src)
{
	char *ret = dest;

	while ((*dest++ = *src++))
		;
	return (ret);
}
/**
 *_strcat - concatenate src to dest
 *@dest: destiny
 *@src: source string
 *Return: return pointer to new string
 */

char *_strcat(char *dest,  char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while ((*dest++ = *src++))
		;
	return (ret);
}
/**
 *ft_strdup - copy src to a location in heap
 *@src: source string
 *Return: return pointer to new string
 */

char *ft_strdup(char *src)
{
	char *str;
	char *p;
	int len = 0;

	while (src[len])
		len++;
	str = malloc(len + 1);
	if (str == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}

	p = str;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (str);
}
/**
 *_strncmp - compare string1 wit string2
 *@s1: string 1
 *@s2: string2
 *@n: number of bytes to compare
 *Return: return 0 if equal
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	while (n--)
		if (*s1++ != *s2++)
			return (*(unsigned char *)(s1 - 1) - *(unsigned char *)(s2 - 1));
	return (0);
}
/**
 *_strcmp - compare string1 wit string2
 *@s1: string 1
 *@s2: string2
 *Return: return 0 if equal
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

