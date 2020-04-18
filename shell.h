#ifndef SHELL_H
#define SHELL_H

#define TOKEN_DELIMITERS " \t\r\n\a :"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <string.h>

/* Global variables */
#define STATUS 1
extern char **environ;
/*int c_count;*/

/* Structs */

/**
 * struct Error - error model
 * @status: status of the error
 * @msg: error message
 * Description: This is the model for the error structure
 */
typedef struct Error
{
	int status;
	char *msg;
} errors_t;


/* Utils functions */
size_t _strlen(const char *str);
char *_strcpy(char *destination, const char *source);
char *_strcat(char *str1, const char *str2);
char *_getenv(const char *name);
char *_check_cwd(char **command);
char *_convert(long int num, int base);
int _strncmp(char *s1, const char *s2, int size);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_check_empty_path(char *path, char **command);
char *_strstr(char **s1, char *s2);
char *_strpbrk(char *s, char *accept);
char *tokenizer_path_mod(char **path_mod, int size, char **commands);
void count_for_cwd(char *path_dup, int *n_dir, int *i, int largo_prueba);
void set_path_mod(char **, char *, int);

/* Shell functions */
void _signals(int signal);
void _free(char **arguments, int ac);
void _loop(int argc, char **arguments);
char **_split_string(char *line);
char *_get_prompt(void);
char *_which(char **arguments);
int _builtin(char **arguments, int ac);
int _fork(char **arguments, char **command, int ac, int counter);
int _exec(char **arguments, char **command, int counter);
int _stat(const char *path);
int _stat_dir(const char *filename);
int _error(char **command, char **arguments, int error, int counter);


#endif
