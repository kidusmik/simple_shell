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
	int status = 0;
	int i = 0;
	int read = 0;
	size_t len = 0;
	int arg_len = 32;
	char *line = NULL, *args[arg_len], *token = NULL;
	char *delim_args = " \t\r\n\v\f";

	/*	- determine an interactive mode or not
		- isatty: checkes if FD is valid or not
	 */
	isatty(STDIN_FILENO) == 0 ? interactive = 0 : interactive;

	while (19)
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
			return (status);
		}
		/* 
			if command is exit then exit form the shell
		 */
		else if (_strncmp(line, "exit\n", 4) == 0)
		{
			free(line);
			return (status);
		}
		else
		{
			if (_strncmp(line, "env\n", 3) == 0)
				print_env(env);
			else if (read > 1)
			{
				token = strtok(line, delim_args);
				args[0] = av[0];
				for (i = 1; i < arg_len && token != NULL; i++)
				{
					args[i] = token, token = strtok(NULL, delim_args);
				}
				args[i] = NULL;
				if (args[1])
				{
					status = create_process(args, execution_counter, env);
				}
			}
			execution_counter++;
		}
	}
	return (status);
}
