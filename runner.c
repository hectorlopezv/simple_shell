#include "shell.h"

int main (int ac, char **argv)
{
	int c_number, status;
	char *buffer_line;
	size_t n_bytes_line;
	char **collection_string, *c_number_char, *path, *check_path;

	buffer_line = NULL, collection_string = NULL, path = NULL;
	n_bytes_line = 0, c_number = 0, status = 0;
	signal(SIGINT, sig_handler);

	while(1)
	{
		c_number++;/*count line*/
		//		printf("count # %d\n",c_number);
		if(isatty(STDIN_FILENO) == 1)
			_prompt();
		if(getline(&buffer_line, &n_bytes_line, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			free(buffer_line);
			buffer_line = NULL;
			if(path != NULL){
				free(path);
				path = NULL;
			}
			if (collection_string != NULL){
				_free(collection_string);
				collection_string = NULL;
			}

			if(isatty(STDIN_FILENO) == 0)/* si es modo no it retorna ultimo commando del status del  hijo*/
				exit(status);
			break;
		}

		if(buffer_line != NULL)
		{
			buffer_line[_strlen(buffer_line) - 1] = 0;

			printf("obvio\n");
			if (_is_empty(buffer_line) == 1)
				continue;


			/*   printf("%s\n",environ[0]);*/
			collection_string = _tokenizer(buffer_line);

			if (collection_string[0] != NULL && collection_string != NULL)
				_builtin(collection_string[0], buffer_line, collection_string);
			path = _which(collection_string);
			/*printf("path econtrado %s\n",path);*/
			if (path == NULL)
			{
				check_path = _check_cwd(collection_string);
				if (check_path != NULL)
				{
					path = ft_strdup(check_path);
				}
				c_number_char = convert(c_number, 10);
				write(STDERR_FILENO, argv[0], _strlen(argv[0]) );
				write(STDERR_FILENO, ": ", 2);
				write(STDERR_FILENO, c_number_char, _strlen(c_number_char));
				write(STDERR_FILENO, ": ", 2);
				write(STDERR_FILENO, collection_string[0],_strlen(collection_string[0]));
				write(STDERR_FILENO, ": not found\n", 12);
				status = 127;
				if (path != NULL)
					free(path);
				if (collection_string != NULL)
					_free(collection_string);
				path = NULL, collection_string = NULL;
				continue;
			}

			// builtIn ,  path= -> cwd ,  PATH ->cwd->NULL

			//status = _fork(path, collection_string);
			//	if(status == -1)

		}
	}
}


void _prompt(void)
{
	write(STDIN_FILENO, "$ ", 2);
}
;
void sig_handler(int num)
{

	write(1, "\n", 1);
	_prompt();

}


char **_tokenizer(char *buffer_line)
{
	int i;
	char *piece;
	char **pieces;
	pieces = malloc( sizeof(char *) * 100);/*100 char pointer*/
	if (pieces ==  NULL)
		return (pieces);

	piece = strtok(buffer_line, TOKEN_DELIMITERS);
	i = 0;
	while (piece != NULL)
	{
		if(_is_empty(buffer_line) == 0)
		{

			pieces[i] = ft_strdup(piece);/*space for the string*/
			printf("lo que metio al array %s\n",pieces[i]);
		}
		i++;
		piece = strtok(NULL, TOKEN_DELIMITERS);
	}
	pieces[i] = NULL;
	return (pieces);/* malloc*/
}


int _strlen(char *buffer)
{
	int i;

	for(i = 0; buffer[i] != 0; i++)
	{

	}
	return(i);/* '\0' lo tiene en cuenta*/
}



int _is_empty(const char *s)
{
	while (*s != '\0')
	{
		if (_isspace((unsigned char)*s) == 0)
			return (0);
		s++;
	}
	return (1);
}

/**
 *  * _isspace - Function that compares c to check if it is one of the cases
 *   * @c: Character to be checked on
 *    *
 *     * Return: 0 if any character is one of the cases,
 *      * or 1 otherwise
 *       *
 *        */
int _isspace(int c)
{
	return (c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}


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
 *  *tokenizer_path_mod - tokenized path_mod
 *   *@path_mod: path_modified
 *    *@size: size of the command
 *     *@command: command  inputed
 *      *Return: return the path_mod fill
 *       */
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

		path_pointer = strtok(NULL,TOKEN_DELIMITERS);
		free(aux);
		aux = NULL;
	}
	return (NULL);

}

/**
 *  *count_for_cwd- fill path in the path_modifief
 *   *@path_dup: duplicated path
 *    *@n_dir: number of dir
 *     *@i: i
 *      *@largo_prueba: largo of the path
 *       *Return: return the number of dir
 *        */
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
 *  * _check_cwd - Check current folder
 *   * @command: Command received
 * Return: pointer string with found path or NULL in failure.
 *     */
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
 *  * _check_empty_path - Check if path is empty
 *   * @command: Command received
 *    * @path: Path of the environ argument
 *     * Return: pointer string with found path or NULL in failure.
 *      */

char *_getenv(char *name, char **env)
{

	size_t  i;
	char *p;
	printf("hello1\n");
	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], name, 4) == 0)
		{
			printf("hello2\n");
			printf("%s\n",env[i]);
			p = env[i];
			return (p);
		}

	}
	return (NULL);
}

int _strcmp(char* s1, char* s2)
{
	while(*s1 && (*s1==*s2))
		s1++,s2++;
	return *(const unsigned char*)s1-*(const unsigned char*)s2;
}

int _strncmp(char* s1, char* s2, size_t n)
{
	while(n--)
		if(*s1++!=*s2++)
			return *(unsigned char*)(s1 - 1) - *(unsigned char*)(s2 - 1);
	return 0;
}

int _stat(const char *filename)
{
	struct stat st;

	if (stat(filename, &st) == 0 && (st.st_mode & S_IXUSR) && (S_ISREG(st.st_mode)))
	{
		/* printf("aqui bebe\n");*/
		return (0);
	}

	return (-1);
}
/**
 *  * _stat_dir - check if dir and if posible to read
 *   * @filename: filename to verify status.
 *    * Return: 1 on sucess, 0 on failure.
 *     */
int _stat_dir(const char *filename)
{
	struct stat st;
	if(stat(filename,&st) ==0 && (S_ISDIR(st.st_mode)) && (st.st_mode & S_IRUSR))
	{
		return (0);
	}
	return (-1);
}
char *ft_strdup(char *src)
{
	char *str;
	char *p;
	int len = 0;

	while (src[len])
		len++;
	str = malloc(len + 1);
	p = str;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return str;
}


char *_strcpy(char *dest, char* src)
{
	char *ret = dest;
	while (*dest++ = *src++)
		;
	return ret;
}

char *_strcat(char *dest,  char *src)
{
	char *ret = dest;
	while (*dest)
		dest++;
	while (*dest++ = *src++)
		;
	return ret;
}

char *_check_empty_path(char *path, char **command)
{
	if (_strcmp(path, "PATH=") == 0)
	{
		printf("entro en check if\n");

		if (_stat_dir(command[0]) == 0)/*if is in cwd and its a dir and read*/
		{
			return (command[0]);
		}
		else if (_stat(command[0]) == 0)/*id is a file and executable*/
		{
			printf("entro en check file\n");
			return (command[0]);
		}

	}

	return (NULL);
}

void _free(char **parsed_buffer)
{
	int i;

	for (i = 0; parsed_buffer[i] != NULL; i++)
		free(parsed_buffer[i]);

	free(parsed_buffer);

}

char *_which(char **collection_string)
{

	int c_number, largo_prueba, size, n_dir;
	char *path, *check_path, *path_dup, *path_mod, *path_mod_tmp;

	n_dir = 0,
		  c_number=0;
	path_mod = NULL;
	path_dup = NULL;
	check_path = NULL;
	size = _strlen(collection_string[0]);
	path = _getenv("PATH", environ);
	if (path == NULL)/*no path in environ*/
	{
		if (_stat(collection_string[0]) == 0){
			return (collection_string[0]);
		}
		return (NULL);
	}

	check_path = _check_empty_path(path, collection_string);/* CHECK IF PATH empty PATH=*/
	if (check_path != NULL)
	{
		return (check_path);/*if cwd if not look in path*/
	}
	path_dup = ft_strdup(path);/*malloc*/
	largo_prueba = _strlen(path_dup);
	count_for_cwd(path_dup, &n_dir, &c_number, largo_prueba);/*count cases .: :: :.*/
	//	printf("el numero de directorios encontrados con los casos especiales %d\n", n_dir);
	//	printf("numero de casos normales %d\n", c_number);
	path_mod = malloc((c_number + n_dir) * sizeof(char));
	path_mod_tmp = path_mod;/*malloc*/
	set_path_mod(&path_mod, path_dup, largo_prueba);/*modifiy*/
	//printf("path modificado %s\n",path_mod);
	path_mod += 5;/*move pointer to =*/
	//printf("path modificado corrido %s\n",path_mod);

	check_path = tokenizer_path_mod(&path_mod, size, collection_string);/*malloc*/

	free(path_dup);/*trash*/
	free(path_mod_tmp);
	path_dup = NULL;
	path_mod_tmp = NULL;

	if (check_path != NULL)   {/*check path then cwd*/
		return (check_path);/*if aux is returned it will be freed in child*/
	}
	/*no path ,no cwd*/
	check_path = NULL;
	return (NULL);/* NO ES CWD O PATH*/
}

int _builtin(char *builtIn,char *buffer_line, char **collection_string)
{
	if (_strcmp(builtIn, "exit") == 0)
	{
		free(buffer_line);
		if (collection_string != NULL)
			_free(collection_string);
		exit(EXIT_SUCCESS);
	}
	return (-1);
}

char *convert(long int num, int base)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long   n;

	array = "0123456789abcdef";
	n = num;
	if (num < 0)
	{
		n = -num;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';
	do      {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}

int _fork(char *path, char **commands)
{
	int status;
	pid_t c_pid, pid;

	c_pid = fork();
	if (c_pid == 0)/*child*/
	{
		//			if (_exec(path,commands) == -1)
		//			{
		//				status = 126;
		//				exit(status);/* permissin denied*/
		//			}
		/*estamos ene l hijo*/
		printf("SOY EL HIJO\n");
	}
	else if (c_pid > 0)
	{
		pid = wait(&status);
		if (pid < 0)/*error*/
			exit(EXIT_FAILURE);
		if (WIFEXITED(status) == 1)/*EXIT normaly*/
			status = WEXITSTATUS(status);
		return (status);
	}
	else{

		exit(EXIT_FAILURE);
	}
	return(-1);/*error on fork look errno*/
}


int _exec(char *path, char **commands)
{
	if (execve(path, commands, environ) == -1)
		return (-1);

	return (0);
}
