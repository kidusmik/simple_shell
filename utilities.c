#include "hsh.h"

/**
* check_command - checks if the command file exists
* @command_file: the command file
* @prompt: the prompt string
*
* Return: 0 if it exists, otherwise 1
*/
int check_command(char *command_file, char *prompt)
{
	int stat_f;

	stat_f = access(command_file, X_OK);
	if (command_file == NULL)
	{
		printf("%s", prompt);
		return (1);
	}

	else if (stat_f != 0)
		return (1);

	return (0);
}

/**
* find_command - finds the command in the environment
* @command_file: the command
* @path: the path list
* @prompt: the prompt
*
* Return: pointer to the command found
*/
char *find_command(char *command_file, char **path, char *prompt)
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
	perror(command_file);
	print_prompt(prompt);

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
