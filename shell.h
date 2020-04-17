#ifndef SHELL_H
#define SHELL_H

#define TOKEN_DELIMITERS " \t\r\n\a :"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

/* Global variables */
#define STATUS 1
extern char **environ;
/* Structs */

/**
 * struct Error - error model
 * @status: status of the error
 * @message: error message
 * Description: This is the model for the error structure
 */
typedef struct Error
{
	int status;
	char *message;
} errors_t;

/**
 * struct Information - General Info model
 * @program_status: status for iterative or non iterative
 * @arguments_to_be_freed: malloc arguments to be free
 * @arguments_count: number of line in the shell
 * @execution: return int for fork()
 * @error_status: error status for child process
 * @line: input line by the user
 * @command: command to execute
 * @tokenized: parsed line input
 * @arguments: arguments for execve
 * Description: struct containing all information for the shell
 */
typedef struct Information
{
	int program_status;
	int arguments_to_be_freed;
	int arguments_count;
	int error_status;
	int execution;
	char *line;
	char *command;
	char **tokenized;
	char **arguments;
} info_t;

/* Shell functions */
void _signals(int signal);
void _free(info_t *info);
char **_tokenizer(info_t *info);
char *_get_prompt(info_t *info);
char *_which(info_t *info);
char *_check_cwd(char*, info_t *info);
int _stat(const char *path);
int _loop(info_t *info);
int _builtin(info_t *info);
int _fork(info_t *info);
int _exec(info_t *info);
int _error(info_t *info);

/* Utils functions */
size_t _strlen(const char *str);
char *_strcpy(char *destination, const char *source);
char *_strcat(char *str1, const char *str2);
char *_getenv(const char *name);
char *_convert(long int num, int base);
int _strncmp(char *s1, const char *s2, int size);
int _strcmp(char *s1, char *s2);
#endif
