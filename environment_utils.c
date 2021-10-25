#include "main.h"

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
	int i;
	int buff_size;

	buff_size = 8 + pid_length;
	i = 0;
	env_value = malloc(sizeof(char) * buff_size);

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
