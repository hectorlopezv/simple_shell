#include "shell.h"
/**
 * _error - handle errors of the program
 * @arguments: Invalid argument
 * @command: Name of the program
 * @error: Integer that decides the error type
 * @count: Variable that counts the number of commands
 * Return: The error integer or 0 in any other case
 */
int _error(char **arguments, char **command, int error, int count)
{
	int i;
	char *count_char;

	errors_t errors[] = {
		{1, ": not found"},
		{2, "failed parsing the line"},
		{290, ""},
		{0, NULL}
	};
	count_char = _convert(count, 10);

	for (i = 0 ; errors[i].status != 0 ; i++)
	{
		if (error == errors[i].status)
		{
			write(STDERR_FILENO, command[0], _strlen(command[0]) - 1);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, count_char, _strlen(count_char - 1));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, arguments[0], _strlen(arguments[0]) - 1);
			write(STDERR_FILENO, errors[i].msg, _strlen(errors[i].msg) - 1);
				write(STDERR_FILENO, "\n", 1);

			return (errors[i].status);
		}
		else if (error == 290)
		{
			perror("");
			return (290);
		}
	}
	return (0);
}

/**
* struct information - struct containing all information for the shell
*@program_status: status for iterative or non iterative
*@arguments_to_be_freed: malloc arguments to be free
*@arguments_count: number of line in the shell
*@execution: return int for fork()
*@error_status: error status for child process
*@line: input line by the user
*@command: command to execute
*@tokenized: parsed line input
*@arguments: arguments for execve 
*Description: struct containing all information for the shell
*/

typedef struct Information
{
	int program_status;
	int arguments_to_be_freed;
	int arguments_count;
	int execution;
	int error_status;
	char *line;
	char *command;
	char **tokenized;
	char **arguments;
} info_t;

