#include "hsh_main.h"

char *get_prompt(char **env)
{
	char *hsh_pid_env_name, *hsh_pid_str, *this_pid_str;
	pid_t this_pid, hsh_pid;
	int pid_length, env_count;

	hsh_pid_env_name = "HSHPID";
	this_pid = getpid();
	hsh_pid_str = getenv(hsh_pid_env_name);
	this_pid_str = pid_to_str(this_pid);

	if (hsh_pid_str == NULL)
	{
		pid_length = len_pid(this_pid);
		env_count = count_env_vars(env);
		_setenv(hsh_pid_env_name, this_pid_str, env_count, pid_length, env);
		hsh_pid = this_pid;
	}
	else
		hsh_pid = str_to_pid(hsh_pid_str);

	return (this_pid > hsh_pid ? "($) " : "$ ");
}

void print_prompt(char *prompt)
{
	printf("%s", prompt);
}

void get_each_paths(char **path)
{
	char *path_buff, *path_dup, *paths, *path_env_name;
	int i;

	path_env_name = "PATH";
	path_buff = getenv(path_env_name);
	path_dup = _strdup(path_buff);
	paths = strtok(path_dup, ":");

	i = 0;
	while (paths)
	{
		path[i] = paths;
		paths = strtok(NULL, ":");
		i++;
	}
	path[i] = NULL;
}

void get_each_command_argv(char **command_argv, char *input_buffer)
{
	char *args, *delim_args;
	int i;

	delim_args = " \t\r\n\v\f";
	args = strtok(input_buffer, delim_args);

	i = 0;
	while (args)
	{
		command_argv[i] = args;
		args = strtok(NULL, delim_args);
		i++;
	}
	command_argv[i] = NULL;
}
