#include "shell.h"

char **_tokenizer(char *buffer_line)
{
	int i;
	char *piece, **pieces;

	pieces = malloc(sizeof(char *) * 100);/*100 char pointer*/
	if (pieces ==  NULL)
		return (pieces);
	piece = strtok(buffer_line, TOKEN_DELIMITERS);
	i = 0;
	while (piece != NULL)
	{
		if (_is_empty(buffer_line) == 0)
		{
			pieces[i] = ft_strdup(piece);/*space for the string*/
		}
		i++;
		piece = strtok(NULL, TOKEN_DELIMITERS);
	}
	pieces[i] = NULL;
	return (pieces);/* malloc*/
}



char *_which(char **collection_string)
{

	int c_number, largo_prueba, size, n_dir;
	char *path, *check_path, *path_dup, *path_mod, *path_mod_tmp;
	n_dir = 0, c_number = 0;
	path_mod = malloc(1), path_dup = malloc(1);
	check_path = NULL;
	size = _strlen(collection_string[0]);
	path = _getenv("PATH=");
	if (path != NULL)/* PATH= case empty*/
	{
		check_path = _check_empty_path(path, collection_string);
		if (check_path != NULL)
		{
			free(path_dup), free(path_mod);
			path_dup = NULL, path_mod = NULL;
			return (ft_strdup(check_path));/*malloc*/
		}
	}
	if (path == NULL)
	{
		free(path_dup), free(path_mod);
		path_dup = NULL, path_mod = NULL;
		check_path = _check_cwd(collection_string);
		if (check_path != NULL)
		{
			return (ft_strdup(check_path));
		}
		return (NULL);
	}
	free(path_dup), free(path_mod);
	path_dup = ft_strdup(path);/*malloc*/
	largo_prueba = _strlen(path_dup);
	count_for_cwd(path_dup, &n_dir, &c_number, largo_prueba);
	path_mod = malloc((c_number + n_dir) * sizeof(char));
	path_mod_tmp = path_mod;/*malloc*/
	set_path_mod(&path_mod, path_dup, largo_prueba);/*modifiy*/
	path_mod += 5;/*move pointer to =*/
	check_path = tokenizer_path_mod(&path_mod, size, collection_string);/*malloc*/
	if (path_dup != NULL)
	{
		free(path_dup), path_dup = NULL;
	}
	if (path_mod_tmp != NULL)
	{
		free(path_mod_tmp), path_mod_tmp = NULL;
	}
	if (check_path != NULL)/*check path then cwd*/
		return (check_path);/*if aux is returned it will be freed in child*/
	return (NULL);/* NO ES CWD O PATH*/
}

