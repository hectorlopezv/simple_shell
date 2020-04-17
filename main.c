#include "shell.h"
/**
 * main - Entry point
 * @av: Arguments of the stdin
 * @ac: Number of arguments
 * Return: EXIT_SUCCESS
 */
int main(int ac, char **av)
{
	info_t *info;
	int status;

	info = malloc(sizeof(info_t));

	info->arguments_to_be_freed = ac;
	info->arguments_count = 0;
	info->execution = 0;
	info->error_status = 0;
	info->command = NULL;
	info->line = NULL;
	info->tokenized = NULL;
	info->arguments = av;
	info->program_status = 0;

	status = _loop(info);

	free(info);
	return (status);
}
