#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
 #include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define TOKEN_DELIMITERS " \t\r\n\a :"
extern char **environ;

/*erros*/

int error_shell(int c_number, char **argv, char **colection_string);

/*parsing*/
char **_tokenizer(char *buffer_line);
char *_which(char **collection_string);

/*signal_prompt*/
void _prompt(void);
void sig_handler(int num);
char *_getenv(char *name);


/*PATH*/
void set_path_mod(char **path_mod, char *path_dup, int largo_prueba);
char *tokenizer_path_mod(char **path_mod, int size, char **command);
void count_for_cwd(char *path_dup, int *n_dir, int *i, int largo_prueba);
char *_check_cwd(char **command);
char *_check_empty_path(char *path, char **command);


/*fork*/
int _fork(char *path, char **commands);


/*utils*/
int _isspace(int c);
int _is_empty(const char *s);
void _free(char **parsed_buffer);
int _builtin(char *builtIn, char **, char ***);
void _free_2(char ***parsed_buffer, char **path);

/*string_utils*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest,  char *src);
char *ft_strdup(char *src);
int _strncmp(char *s1, char *s2, size_t n);
int _strcmp(char *s1, char *s2);


/*string_utils_2*/
int _strlen(char *buffer);
char *_convert(long int num, int base);

/*validation*/
int _stat_dir(const char *filename);
int _stat(const char *filename);


#endif
