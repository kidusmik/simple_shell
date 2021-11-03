#include "hsh.h"
/**
 * _getenv - get variable enviriomment
 * @name: name the variable envirionment
 * @env: environment variable
 * Return: char value envirionment
 **/
char *_getenv(char *name, char **env)
{
	char *token1 = NULL, *token2 = NULL;
	char *env_name = NULL, *current_env = NULL;
	int i = 0;

	env_name = _strdup(name);

	while (env[i] && env)
	{
		current_env = NULL;
		token2 = NULL;
		current_env = _strdup(env[i]);
		token1 = strtok(current_env, "=");
		token2 = _strdup(strtok(NULL, "="));
		if (_strcmp(env_name, token1) == 0)
		{
			break;
		}
		free(current_env);
		free(token2);
		i++;
	}
	free(current_env);
	current_env = NULL;
	free(env_name);
	return (token2);
}

/**
 * _memset - fills memory with a constant byte.
 * @s: address begin to fill
 * @b: value to set on memory
 * @n: numbers of bytes to pointed by s
 * Return: char
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int cont = 0;

	while (cont < n)
	{
		*(s + cont) = b;
		cont++;
	}
	return (s);
}

/**
 * _calloc - function that allocates memory for an array, using malloc
 * @nmemb: amount to values to store on memory
 * @size: number of bytes of datatype
 *
 * Return: Void pointer
 */
void *_calloc(unsigned int nmemb, int size)
{
	void *p = NULL;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(nmemb * size);

	if (p == NULL)
		return (NULL);

	_memset(p, 0, size * nmemb);
	return (p);
}

/**
 * print_env - print variable global envirionment
 * @env: variable global envirionment system
 * Return: estatus_exit value;
 **/

void print_env(char **env)
{
	int i = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 *_strncmp -  function that compares two strings.
 *@s1: string one
 *@s2: string two
 *@n: number of characters
 * Return: diference
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	int i = 0, j = 0;

	while (n && s1[i] && (s1[i] == s2[j]))
	{
		i++;
		j++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[j]);
	}
}
