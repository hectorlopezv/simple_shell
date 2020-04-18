#include "shell.h"
/**
 * _which - Find the directory needed
 * @command: Command received
 *
 * Return: pointer string with found path or NULL in failure.
 */
char *_which(char **command)
{

	char *path, *check_path, *path_dup, *path_mod, *path_mod_tmp;
	int size, i, n_dir, largo_prueba;

	n_dir = 0, i = 0;
	size = _strlen(command[0]);
	if (!command)
		return (NULL);
	path = _getenv("PATH");
	if (path == NULL)/*no path in environ*/
	{
		if (_stat(command[0]) == 0)
			return (command[0]);
		return (NULL);
	}
	check_path = _check_empty_path(path, command);/* CHECK IF PATH empty PATH=*/
	if (check_path != NULL)
		return (check_path);/*if cwd if not look in path*/

	path_dup = _strdup(path);/*malloc*/
	largo_prueba = _strlen(path_dup) - 1;
	count_for_cwd(path_dup, &n_dir, &i, largo_prueba);/*count cases .: :: :.*/
	path_mod = malloc((i + n_dir) * sizeof(char));
	path_mod_tmp = path_mod;/*malloc*/
	set_path_mod(&path_mod, path_dup, largo_prueba);/*modifiy*/
	path_mod += 5;/*move pointer to =*/

	check_path = tokenizer_path_mod(&path_mod, size, command);/*malloc*/
	free(path_mod_tmp);/*trash*/
	free(path_dup);/*trash*/
	if (check_path != NULL)/*check path then cwd*/
		return (check_path);/*if aux is returned it will be freed in child*/

	return (NULL);/*no path ,no cwd*/


}

