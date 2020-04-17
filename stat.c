#include "shell.h"
/**
 * _stat - stat of a file.
 * @filename: filename to verify status.
 * Return: 1 on sucess, 0 on failure.
 */
int _stat(const char *filename)
{
	struct stat st;

	if (stat(filename, &st) == 0
			&& (st.st_mode & S_IXUSR)
			&& (S_ISREG(st.st_mode)))
	{
		return (0);
	}

	return (-1);
}
/**
 * _stat_dir - check if dir and if posible to read
 * @filename: filename to verify status.
 * Return: 1 on sucess, 0 on failure.
 */
int _stat_dir(const char *filename)
{
	struct stat st;

	if (stat(filename, &st) == 0
			&& (S_ISDIR(st.st_mode))
			&& (st.st_mode & S_IRUSR))
	{
		return (0);
	}
	return (-1);
}

