#include "shell.h"
/**
 *set_path_mod - fill copy of mod path
 *@path_mod: mod path
 *@path_dup: path duplicate
 *@largo_prueba: length of command
 *Return: return a modified path_mod
 */
void set_path_mod(char **path_mod, char *path_dup, int largo_prueba)
{
	int i, j;

	for (i = 0, j = 0; path_dup[i]; i++)
	{
		(*path_mod)[j] = path_dup[i];
		if (path_dup[i] == '=' && path_dup[i + 1] == ':')
		{
			j++;
			(*path_mod)[j] = '.';
		}
		if (path_dup[i] == ':' && path_dup[i + 1] == ':')
		{
			j++;
			(*path_mod)[j] = '.';
		}
		if (i == largo_prueba - 1)
		{
			if (path_dup[i] == ':' && path_dup[i + 1] == 0)
			{
				j++;
				(*path_mod)[j] = '.';
			}
		}
		j++;
	}

	(*path_mod)[j] = 0;
}

/**
 *tokenizer_path_mod - tokenized path_mod
 *@path_mod: path_modified
 *@size: size of the command
 *@command: command  inputed
 *Return: return the path_mod fill
 */

char *tokenizer_path_mod(char **path_mod, int size, char **command)
{
	char *path_pointer, *aux;

	path_pointer = strtok(*path_mod, TOKEN_DELIMITERS);

	while (path_pointer != NULL)
	{
		aux = malloc(_strlen(path_pointer) + size + 2);/*MALLOC*/
		if (!aux)
			return (aux);
		aux = _strcpy(aux, path_pointer);
		aux = _strcat(aux, "/");
		aux = _strcat(aux, command[0]);
		if (_stat(aux) == 0)
			return (aux);/*RETORNA MALLOC*/

		path_pointer = strtok(NULL, TOKEN_DELIMITERS);
		free(aux);
	}
	return (NULL);

}

/**
 *count_for_cwd- fill path in the path_modifief
 *@path_dup: duplicated path
 *@n_dir: number of dir
 *@i: i
 *@largo_prueba: largo of the path
 *Return: return the number of dir
 */
void count_for_cwd(char *path_dup, int *n_dir, int *i, int largo_prueba)
{
	/*count*/
	for (; path_dup[*i]; (*i)++) /*cases .:   ::   :.  */
	{
		if (path_dup[*i] == '=' && path_dup[(*i) + 1] == ':')
		{
			(*n_dir)++;
		}
		if (path_dup[*i] == ':' && path_dup[(*i) + 1] == ':')
		{
			(*n_dir)++;
		}
		if (*i == largo_prueba - 1)
		{
			if (path_dup[*i] == ':' && path_dup[(*i) + 1] == 0)
			{
				(*n_dir)++;
			}
		}
	}
	(*i)++;/*character nullo*/
}


/**
 *_check_cwd - Check current folder
 *@command: Command received
 *Return: pointer string with found path or NULL in failure.
 */
char *_check_cwd(char **command)
{
	if (_stat_dir(command[0]) == 0)/*if is in cwd and its a dir and read*/
	{
		return (command[0]);
	}
	else if (_stat(command[0]) == 0)/*id is a file and executable*/
	{

		return (command[0]);
	}


	return (NULL);
}

/**
 *_check_empty_path - check if path is empty
 *@path: path to compare
 *@command: command to look
 *Return: NUll if not in cwd othervise path to file
 */
char *_check_empty_path(char *path, char **command)
{
	if (_strcmp(path, "PATH=") == 0)
	{

		if (_stat_dir(command[0]) == 0)/*if is in cwd and its a dir and read*/
		{
			return (command[0]);
		}
		else if (_stat(command[0]) == 0)/*id is a file and executable*/
		{
			return (command[0]);
		}

	}

	return (NULL);
}
