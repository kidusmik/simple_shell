#include "hsh_main.h"

/**
* main - entry point for the hsh shell
*
* Return: Always 0.
*/
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv, char **env)
{
	pid_t this_pid, hsh_pid;
	char *hsh_pid_str, *hsh_pid_env_name, *this_pid_str;
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

	run_parent_shell(hsh_pid, this_pid, env);

	return (0);
}
