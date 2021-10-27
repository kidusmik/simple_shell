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
	int ret;
	size_t b_size;
	ssize_t chk_line;

	prompt = get_prompt(env);
	/* print_prompt(prompt); */
	get_each_paths(path);
	b_size = 32;
	input_buffer = malloc(sizeof(char) * b_size);
	chk_line = 1;
	while (chk_line)
	{
		print_prompt(prompt);

		if (line_input_check(&input_buffer, &b_size, stdin, &chk_line))
			continue;

		get_each_command_argv(command_argv, input_buffer);

		if (command_argv[0] == NULL)
			continue;

		command = find_command(command_argv[0], path);
		if (command == NULL)
		{
			printf("%s: No such file or directory\n", command_argv[0]);
			continue;
		}
		ret = execute_command(command, command_argv, env);
		if (ret)
			continue;
	}
	return (0);
}
