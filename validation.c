#include "shell.h"

/**
 *_stat - check if dir and if posible to read
 *@filename: filename to verify status.
 *Return: 1 on sucess, 0 on failure.
 */

int _stat(const char *filename)
{
	struct stat st;

	if (stat(filename, &st) == 0 && (st.st_mode & S_IXUSR)
			&& (S_ISREG(st.st_mode)))
	{
		return (0);
	}
	return (-1);
}
/**
 *_stat_dir - check if dir and if posible to read
 *@filename: filename to verify status.
 *Return: 1 on sucess, 0 on failure.
 */
int _stat_dir(const char *filename)
{
	struct stat st;

	if (stat(filename, &st) == 0 && (S_ISDIR(st.st_mode))
			&& (st.st_mode & S_IRUSR))
	{
		return (0);
	}
	return (-1);
}

/**
 *chech_cwd_exit - check cwd then set error
 *@collection_string: 2d array of commands
 *Return: return path if found otherwise NULL
 */
char *chech_cwd_exit(char **collection_string)
{
	if (_stat(collection_string[0]) == 0)
		return (ft_strdup(collection_string[0]));
	return (NULL);
}

/**
 *check_for_built_in - check for built in
 *@collection_string: 2d array of commands
 *@buffer_line: buffer line
 *@status: exit status
 *@argv: command line arguments
 *@c_number: c_number of line command line
 *Return: 0 if found -1 not found
 */

int check_for_built_in(char ***collection_string, char **buffer_line,
		int *status, char **argv, int c_number)
{

	int built_flag;

	if ((*collection_string)[0] != NULL && *collection_string != NULL)
	{
		built_flag = _builtin(*collection_string[0], buffer_line,
				collection_string, status, argv, c_number);
		if (built_flag == -1)
			return (-1);/* not found*/
	}
	return (0);/*found */
}


/**
 *_atoi - string to number
 *@s: string to be converted
 *Return: return the converted number
 */

int _atoi(char *s)
{
	int n, contador;
	int str, y, i;

	str = 0;
	y = 0;
	i = 0;
	n = 1;
	contador = 0;

	for (i = 0 ; s[i] != '\0'; i++)
	{
		if ((contador > 0) && (s[i] == ' '))
		{ /* break space*/
			str = str;
			break;
		}


		if (s[i] == '-')
		{
			n = n * -1;
		}


		if (s[i] >= '0' && s[i] <= '9')
		{
			contador++;
			y = s[i] - '0';

			str = (str * 10) + y;
		}
	}
	return (str * n);
}
