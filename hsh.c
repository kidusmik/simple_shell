#include "hsh.h"

/**
* main - entry point for the hsh shell
* @argc: arguments count
* @argv: arguments list
* @env: environments list
*
* Return: Always 0.
*/
int main(__attribute__((unused)) int argc, char **argv,
		char **env)
{
	char *input_buffer, *prompt, *command_argv[50], *path[50], *command;
	int ret, mode, ret_value, exec_count;
	size_t b_size;

	exec_count = 0;
	ret_value = 0;
	prompt = "($) ";
	mode = isatty(STDIN_FILENO);
	print_prompt(prompt, mode, &exec_count);
	get_each_paths(path, env);
	b_size = 32;
	input_buffer = malloc(sizeof(char) * b_size);
	while (getline(&input_buffer, &b_size, stdin) != -1)
	{
		get_each_command_argv(command_argv, input_buffer);
		if (command_argv[0] == NULL)
		{
			print_prompt(prompt, mode, &exec_count);
			continue;
		}
		command = find_command(command_argv[0], path, prompt,
					mode, argv[0], &ret_value, &exec_count);
		if (command == NULL)
			continue;
		ret = execute_command(command, command_argv, env, prompt,
					mode, &exec_count);
		if (ret)
		{
			print_prompt(prompt, mode, &exec_count);
			continue;
		}
	}

	return (ret_value);
}
