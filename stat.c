#include "shell.h"
/**
 * _stat - stat of a file.
 * @filename: filename to verify status.
 * Return: 1 on sucess, 0 on failure.
 */
int _stat(const char *filename)
{
	struct stat st;

	if (stat(filename, &st) == 0 && (st.st_mode & S_IXUSR))
		return (0);

	return (-1);
}
