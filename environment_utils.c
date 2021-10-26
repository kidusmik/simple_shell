#include "hsh.h"

int count_env_vars(char **env)
{
	int count;

	count = 0;
	while (env[count] != NULL)
		count++;

	return (count);
}

void _setenv(char *hsh_env_name, char *this_pid_str, int env_count, int pid_length, char **env)
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


void _printenv(char **env)
{
	int i;

	i = 0;
	while(env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
