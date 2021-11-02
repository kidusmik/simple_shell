#include "hsh.h"

/**
* print_prompt - prints the prompt
* @prompt: the prompt string
*
* Return: Always void
*/
void print_prompt(char *prompt, int mode)
{
	int len;

	len = _strlen(prompt);

	if (mode == 1)
		write(STDOUT_FILENO, prompt, len + 1);
}

/**
* get_each_paths - stores the path variables to a list
* @path: the path list
* @env: the environment
*
* Return: Always void
*/
void get_each_paths(char **path, char **env)
{
	char *path_buff, *path_dup, *paths, *path_env_name;
	int i;

	path_env_name = "PATH";
	path_buff = _getenv(path_env_name, env);
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
}

/**
* get_each_command_argv - stores all the arguments \
*             of the input command to the list
* @command_argv: the command argument list
* @input_buffer: the input buffer
*
* Return: Always void
*/
void get_each_command_argv(char **command_argv, char *input_buffer)
{
	char *args, *delim_args;
	int i;

	delim_args = " \t\r\n\v\f";
	args = strtok(input_buffer, delim_args);

	i = 0;
	while (args)
	{
		command_argv[i] = args;
		args = strtok(NULL, delim_args);
		i++;
	}
	command_argv[i] = NULL;
}

/**
* execute_command - executes the command
* @command: the command
* @command_argv: the command arguments list
* @env: the environment list
* @prompt: the prompt string
*
* Return: 1 on success, otherwise 0
*/
int execute_command(char *command, char **command_argv,
				char **env, char *prompt, int mode)
{
	pid_t child_pid;
	int status;

	if (_strcmp(command, "exit"))
		exit(0);
	else if (_strcmp(command, "env"))
	{
		_printenv(env);
		return (1);
	}
	else
	{
		child_pid = fork();

		if (child_pid == -1)
			return (0);

		if (child_pid == 0)
		{
			if (execve(command, command_argv, env) == -1)
				return (0);
		}
		else
		{
			wait(&status);
			print_prompt(prompt, mode);
		}
	}
	return (0);
}
