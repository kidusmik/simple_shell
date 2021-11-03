#include "hsh.h"

/**
* print_error - prints error message
*/
void handle_error(char *prog_name, int *exec_count,
			char *command_file, int *ret_value)
{
	dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", prog_name,
			*exec_count, command_file);

	*ret_value = 127;
}

/**
* find_command - finds the command in the environment
* @command_file: the command
* @path: the path list
* @prompt: the prompt
* @mode: the mode (interactive or non-interactive
* @prog_name: name of the shell
*
* Return: pointer to the command found
*/
char *find_command(char *command_file, char **path, char *prompt,
			int mode, char *prog_name,
			int *ret_value, int *exec_count)
{
	int stat_f, i;
	char *command_path;

	i = 0;
	command_path = malloc(sizeof(char) * 50);
	if (*command_file == '.' || *command_file == '/')
	{
		stat_f = access(command_file, X_OK);
		if (stat_f == 0)
			return (command_file);
	}
	else if (_strcmp(command_file, "exit"))
		return (_strdup("exit"));
	else if (_strcmp(command_file, "env"))
		return (_strdup("env"));

	else
	{
		while (path[i] != NULL)
		{
			_strcat(path[i], command_file, command_path);
			stat_f = access(command_path, X_OK);
			if (stat_f == 0)
				return (command_path);

			i++;
		}
	}
	handle_error(prog_name, exec_count, command_file, ret_value);
	print_prompt(prompt, mode, exec_count);

	return (NULL);
}

/**
* power - find the power of the number
* @a: the base
* @b: the power
*
* Return: the calculated power
*/
int power(int a, int b)
{
	int p_result;

	p_result = 1;
	if (b == 0)
		return (1);
	if (b == 1)
		return (a);
	while (b)
	{
		p_result *= a;
		b--;
	}
	return (p_result);
}
