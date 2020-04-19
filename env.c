#include "shell.h"

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  _setenv
 *  Description:
 * =====================================================================================
 */

int  _setenv (char *variable, char *value)
{
	/*createes the variable=value*/
	char *ep, *new_string;
	printf("esto es el variable %s\n",variable);
	printf("esto es el value %s\n",value);
	if (_strcmp(variable, "=") == 0 || variable == NULL || _strcmp(variable, "") == 0)
	{
		errno = EINVAL;
		return (-1);
	}

	ep = _getenv(variable);
	if (ep != NULL)
		_unsetenv(variable);
	new_string = malloc(_strlen(variable) + 1 +_strlen(value) + 1);/* MALLOC*/
	if (new_string == NULL)
	{
		errno = ENOMEM;
		free(new_string);
		return (-1);
	}
	_strcpy(new_string,variable);
	_strcat(new_string,"=");
	_strcat(new_string,value);
	/*putenv does the changin of the array*/
	if (_putenv(new_string) != -1)
	{   free(new_string), new_string = NULL; /*modify the 2d env array and free if allocated before*/
		return (0);
	}
	free(new_string), new_string = NULL;
	return (-1);/* 0 on success , -1 on failure*/
}		/* -----  end of function _setenv  ----- */


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  _putenv
 *  Description:
 * =====================================================================================
 */

int  _putenv (char * string)
{

	static char **last_environ = NULL;

	char *finded_equal;
	int i, contador, exist_case_flag;
	char *duplicate_out_equal;
	char **new_environ;
	exist_case_flag = 0;
	finded_equal = strchr(string,'=');

	duplicate_out_equal = strndup(string, string - finded_equal);/* copia variable MALLOC*/

	if (last_environ == NULL)
	{
		for (i = 0, contador = 0; environ[i] != NULL; i++)
		{
			if (_strncmp(environ[i], duplicate_out_equal, string - finded_equal) != 0)
				contador++;
		}

		last_environ = malloc ((contador + 2) * sizeof(char *));/* nuevo array, MALLOC*/
		if (last_environ == NULL)
		{
			free(duplicate_out_equal), duplicate_out_equal = NULL;
			errno = ENOMEM;
			return (-1);
		}

		for (i = 0; environ[i] != NULL; i++)
		{
			if (_strncmp(environ[i], duplicate_out_equal, string - finded_equal) == 0)
			{
				last_environ[i] = ft_strdup(string);/*caso que exista y se modifica*/
				if (last_environ[i] == NULL)
				{
					free(duplicate_out_equal), duplicate_out_equal = NULL;
					errno = ENOMEM;
					return (-1);
				}
				exist_case_flag = 1;
			}
			else
			{
				last_environ[i] = ft_strdup(environ[i]);
			}

		}

		free(duplicate_out_equal), duplicate_out_equal = NULL;
		/*caso que no exista y se agrega al final */
		if (exist_case_flag == 0)
			last_environ[i -1] = ft_strdup(string);
		last_environ[i] = NULL;
		environ = last_environ;/*malloc new environ, free in last_environ != NULL*/
		return (0);
	}

	if (last_environ != NULL)
	{
		for (i = 0, contador = 0;last_environ[i] != NULL; i++)
		{
			if (_strncmp(last_environ[i], duplicate_out_equal, string - finded_equal) != 0)
				contador++;
		}

		new_environ = malloc ((contador + 2) * sizeof(char *));/* nuevo array*/
		if (new_environ == NULL)
		{
			errno = ENOMEM;
			return (-1);
		}

		for (i = 0; last_environ[i] != NULL; i++)
		{
			if (_strncmp(last_environ[i], duplicate_out_equal, string - finded_equal) == 0)
			{
				new_environ[i] = ft_strdup(string);/*caso que exista y se modifica*/
				if (new_environ[i] == NULL)
				{
					errno = ENOMEM;
					return (-1);
				}

				exist_case_flag = 1;
			}
			else
			{
				new_environ[i] = ft_strdup(last_environ[i]);
			}

		}

		free(duplicate_out_equal), duplicate_out_equal = NULL;
		_free(last_environ), last_environ = NULL;
		/*caso que no exista y se agrega al final */
		if (exist_case_flag == 0)
			new_environ[i -1] = ft_strdup(string);
		new_environ[i] = NULL;
		environ = last_environ = new_environ;/*malloc new environ, free in last_environ != NULL*/
	}

	return 0;

}



/*
 * ===  FUNCTION  ======================================================================
 *         Name:  _unsetenv
 *  Description:
 * =====================================================================================
 */

int  _unsetenv (char *string)
{
	return 0;
}		/* -----  end of function _unsetenv  ----- */
