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
*  _setenv - sets a new environment path
* @hsh_env_name: the environment name for hsh shell
* @this_pid_str: the current shell's pid
* @env_count: the environment count
* @pid_length: the length of the current shell's pid
* @env: the environment list
*/
void _setenv(char *hsh_env_name, char *this_pid_str,
		int env_count, int pid_length, char **env)
{
	char *env_value;
	int i, str_len;
	size_t buff_size;

	str_len = _strlen(hsh_env_name);
	buff_size = str_len + pid_length + 2;
	env_value = malloc(sizeof(char) * buff_size);
	i = 0;

	while (*hsh_env_name != '\0')
	{
		*(env_value + i) = *hsh_env_name;
		hsh_env_name = hsh_env_name + 1;
		i++;
	}
	*(env_value + i) = '=';
	i++;
	while (*this_pid_str != '\0')
	{
		*(env_value + i) = *this_pid_str;
		this_pid_str = this_pid_str + 1;
		i++;
	}
	*(env_value + i) = '\0';

	env[env_count] = env_value;
	env[env_count + 1] = NULL;
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
		printf("%s\n", env[i]);
		i++;
	}
}
