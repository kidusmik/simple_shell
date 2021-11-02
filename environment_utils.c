#include "hsh.h"

/**
* count_env_vars - counts the environment variables
* @env: the environment list
*
* Return: the count
*/
int count_env_vars(char **env)
{
	int count;

	count = 0;
	while (env[count] != NULL)
		count++;

	return (count);
}

/**
* _printenv - prints the environment list
* @env: the environment list
*
* Return: Always void
*/
void _printenv(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]) + 1);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
* _getenv - get variable enviriomment
* @name: name the variable envirionment
* @env: the environment
*
* Return: pointer to the variable
*/
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
		if (_strcmp(env_name, token1) == 1)
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
*  _setenv - sets a new environment path
* @env_name: the environment name
* @env_value: the environment value
* @env: the environment list
*
* Return: Always Void
*/
void _setenv(char *env_name, char *env_value, char **env)
{
	char *env_store;
	int i, str_len_env, str_len_env_value, env_count;
	size_t buff_size;

	env_count = count_env_vars(env);
	str_len_env = _strlen(env_name);
	str_len_env_value = _strlen(env_value);
	buff_size = str_len_env + str_len_env_value + 2;
	env_store = malloc(sizeof(char) * buff_size);
	i = 0;

	while (*env_name != '\0')
	{
		*(env_store + i) = *env_name;
		env_name = env_name + 1;
		i++;
	}
	*(env_store + i) = '=';
	i++;
	while (*env_value != '\0')
	{
		*(env_store + i) = *env_value;
		env_value = env_value + 1;
		i++;
	}
	*(env_store + i) = '\0';

	env[env_count] = env_store;
	env[env_count + 1] = NULL;
}
