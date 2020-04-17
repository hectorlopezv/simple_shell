#include "shell.h"
/**
 * _loop - exec implementation for Simple Shell.
 * @info: Struct that contains general information.º
 * Return: The status to the main function.
 */
int _loop(info_t *info)
{
	int status;

	while (STATUS)
	{
		signal(SIGINT, _signals);
		_get_prompt(info);
		if (info->line == NULL)
			continue;

		if (info->line[0] == '\n')
		{
			fflush(stdin);
			info->arguments_count += 1;
			free(info->line);
			continue;
		}
		info->tokenized = _tokenizer(info);
		if (!info->tokenized)
		{
			info->error_status = 1;
			_error(info);
		}
		if (info->tokenized[0] != 0)
			_builtin(info);
		info->arguments_count += 1;
		if (_fork(info) == -1)
		{
			info->error_status = 1;
			_error(info);
		}
		free(info->tokenized);
		free(info->line);
		status = info->error_status;
	}
	return (status);
}
