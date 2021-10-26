#include "hsh_main.h"

/**
* main - entry point for the hsh shell
* @argc: arguments count
* @argv: arguments list
* @env: environments list
*
* Return: Always 0.
*/
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv, char **env)
{
	pid_t this_pid, hsh_pid, child_pid;
	char *hsh_pid_str, *hsh_pid_env_name, *this_pid_str;
	char *buffer, *delim, *params, *prompt, *comm_params[50];
	char *path[50], *paths, *command, *path_buff, *path_dup;
	int pid_length, env_count, status, i;
	size_t b_size;
	ssize_t chk_line;

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

	b_size = 32;
	buffer = malloc(sizeof(char) * b_size);
	delim = " \t\r\n\v\f";
	if (this_pid > hsh_pid)
		prompt = "($) ";
	else
		prompt = "$ ";

	printf("%s", prompt);

	path_buff = getenv("PATH");

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
	
	chk_line = 1;
	while (chk_line)
	{
		chk_line = getline(&buffer, &b_size, stdin);
		if (chk_line == EOF || chk_line == -1 || chk_line < 1)
		{
			chk_line = 1;
			continue;
		}

		params = strtok(buffer, delim);

		i = 0;
		while (params)
		{
			comm_params[i] = params;
			params = strtok(NULL, delim);
			i++;
		}
		comm_params[i] = NULL;

		if (comm_params[0] == NULL)
		{
			printf("%s", prompt);
			continue;
		}		
		if (check_exit(comm_params[0]))
			exit(0);

		if(check_printenv(comm_params[0]))
		{
			_printenv(env);
			printf("%s", prompt);
			continue;
		}
/*		if (check_command(comm_params[0], prompt))
			continue;
*/
		command = find_command(comm_params[0], path);
	
		if (command == NULL)
		{
			printf("%s: No such file or directory\n", comm_params[0]);
			printf("%s", prompt);
			continue;
		}

		child_pid = fork();

		if (child_pid == -1)
			return (1);

		if (child_pid == 0)
		{
			if (execve(command, comm_params, env) == -1)
				return (1);
		}
		else
		{
			wait(&status);
			printf("%s", prompt);
		}
	}

	return (0);
}
