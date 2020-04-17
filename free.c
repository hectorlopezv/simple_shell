#include "shell.h"
/**
 * _free - free up a 2d grid
 * @info: Struct that contains general information that goes
 * through out all the program
 */

void _free(info_t *info)
{
	int i;

	for (i = 0; i < info->arguments_to_be_freed; i++)
		free(info->tokenized[i]);

	free(info->tokenized);
}

