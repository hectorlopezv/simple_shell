#include "shell.h"

/**
 *_convert - convert int to string
 *@num: number to convert
 *@base: base of the number
 *Return: return
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
 *_strlen - legth of a string
 *@buffer: buffer
 *Return: return legth of a string
 */
int _strlen(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != 0; i++)
	{

	}
	return (i);/* '\0' lo tiene en cuenta*/
}
