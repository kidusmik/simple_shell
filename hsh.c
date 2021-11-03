#include "hsh.h"

/**
* main - entry point for the hsh shell
* @argc: arguments count
* @argv: arguments list
* @env: environments list
*
* Return: Always 0.
*/
int main(__attribute__((unused)) int argc,
		__attribute__((unused)) char **argv,
		char **env)
{
	char *input_buffer, *prompt, *command_argv[50], *path[50], *command;
	int ret, mode;
	size_t b_size;

	prompt = "($) ";
	mode = isatty(STDIN_FILENO);
	print_prompt(prompt, mode);
	get_each_paths(path, env);
	b_size = 32;
	input_buffer = malloc(sizeof(char) * b_size);
	while (getline(&input_buffer, &b_size, stdin) != -1)
	{
		get_each_command_argv(command_argv, input_buffer);
		if (command_argv[0] == NULL)
		{
			print_prompt(prompt, mode);
			continue;
		}
		command = find_command(command_argv[0], path, prompt, mode);
		if (command == NULL)
			continue;
		ret = execute_command(command, command_argv, env, prompt, mode);
		if (ret)
		{
			print_prompt(prompt, mode);
			continue;
		}
	}

	return (0);
}
