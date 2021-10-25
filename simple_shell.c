#include "hsh_main.h"

/**
* main - entry point for the hsh shell
*
* Return: Always 0.
*/
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv, char **env)
{
	pid_t this_pid, hsh_pid, child_pid;
	char *hsh_pid_str, *hsh_pid_env_name, *this_pid_str;
	char *buffer, *delim, *params, *prompt, *comm_params[2];
	int pid_length, env_count, status;
	struct stat st;
	size_t b_size;

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

	comm_params[1] = NULL;
	b_size = 32;
	buffer = malloc(sizeof(char) * b_size);
	delim = "\n";

	if (this_pid > hsh_pid)
		prompt = "($) ";
	else
		prompt = "$ ";

	printf("%s", prompt);

	while (getline(&buffer, &b_size, stdin) != -1)
	{
		params = strtok(buffer, delim);
		comm_params[0] = params;

		if (check_exit(comm_params[0]))
			exit(0);

		if (check_command(comm_params[0], &st, prompt))
			continue;

		child_pid = fork();

		if (child_pid == -1)
			return (1);

		if (child_pid == 0)
		{
			if (execve(comm_params[0], comm_params, env) == -1)
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
