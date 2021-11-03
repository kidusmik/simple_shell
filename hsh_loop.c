#include "hsh.h"

/**
 * hsh_loop - reads the command line a through getline and determine 
 * the mode either interactive or non-interactive from the command line.
 * @av: Pointer to arrays of string
 * @execution_counter: command execution counter.
 * @env: Enviroment variable.
 * Return: status value.
 **/
int hsh_loop(char *av[], int execution_counter, char **env)
{
	int interactive = 1;
	int process_status = 0;
	int i = 0;
	int read = 0;
	size_t len = 0;
	char *line = NULL, *args[32], *token = NULL;
	/* 
	char *input_buffer, *prompt, *command_argv[50], *path[50], *command;
	int ret;
	

	prompt = get_prompt(env);
	print_prompt(prompt);
	get_each_paths(path);
	b_size = 32;
	input_buffer = malloc(sizeof(char) * b_size);
	while (getline(&input_buffer, &b_size, stdin) != -1)
	{
		get_each_command_argv(command_argv, input_buffer);
		if (command_argv[0] == NULL)
		{
			print_prompt(prompt);
			continue;
		}
		command = find_command(command_argv[0], path, prompt);
		if (command == NULL)
			continue;
		ret = execute_command(command, command_argv, env, prompt);
		if (ret)
		{
			print_prompt(prompt);
			continue;
		}
	}
 */
	/*	- determine an interactive mode or not
		- isatty: checkes if FD is valid or not
	 */
	isatty(STDIN_FILENO) == 0 ? interactive = 0 : interactive;

	while (1)
	{
		interactive == 1 ? write(STDIN_FILENO, "> ", 2) : interactive;

		/* 
			- getline(): reads what has passed on the command line
				requires the address of the lint
				- line = NULL & len = 0 to let getline() authomatically allocate
				a buffer to hold charachters in the line
				- if a line holds a char then it will be read and parsed for execution
		 */
		read = getline(&line, &len, stdin);
		if (read == EOF)
		{
			free(line), write(STDIN_FILENO, "\n", 1);
			return (process_status);
		}
		/* 
			if the command is exit then exit form the shell
		 */
		else if (_strncmp(line, "exit\n", 4) == 0)
		{
			free(line);
			return (process_status);
		}
		else
		{
			if (_strncmp(line, "env\n", 3) == 0)
				print_env(env);
			else if (read > 1)
			{
				token = strtok(line, " \t\r\n\v\f");
				args[0] = av[0];
				for (i = 1; i < 32 && token != NULL; i++)
				{
					args[i] = token;
					token = strtok(NULL, " \t\r\n\v\f");
				}
				args[i] = NULL;
				if (args[1])
				{
					process_status = new_process(args, execution_counter, env);
				}
			}
			execution_counter++;
		}
	}
	return (process_status);
}
