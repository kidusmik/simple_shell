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
	pid_t child_pid;
	char *input_buffer, *prompt, *command_argv[50];
	char *path[50], *command;
	int status;
	size_t b_size;
	ssize_t chk_line;

	prompt = get_prompt(env);

	print_prompt(prompt);

	get_each_paths(path);

	b_size = 32;
	input_buffer = malloc(sizeof(char) * b_size);
	
	chk_line = 1;
	while (chk_line)
	{
		chk_line = getline(&input_buffer, &b_size, stdin);
		if (chk_line == EOF || chk_line == -1 || chk_line < 1)
		{
			chk_line = 1;
			continue;
		}

		get_each_command_argv(command_argv, input_buffer);

		if (command_argv[0] == NULL)
		{
			printf("%s", prompt);
			continue;
		}		
		if (check_exit(command_argv[0]))
			exit(0);

		if(check_printenv(command_argv[0]))
		{
			_printenv(env);
			printf("%s", prompt);
			continue;
		}

		command = find_command(command_argv[0], path);
	
		if (command == NULL)
		{
			printf("%s: No such file or directory\n", command_argv[0]);
			printf("%s", prompt);
			continue;
		}

		child_pid = fork();

		if (child_pid == -1)
			return (1);

		if (child_pid == 0)
		{
			if (execve(command, command_argv, env) == -1)
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
