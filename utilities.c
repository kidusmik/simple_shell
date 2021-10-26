#include "hsh_main.h"

/**
* check_command - checks if the command file exists
* @command_file: the command file
* @st: pointer to structure of stat
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
	{
		printf("%s: No such file or directory\n", command_file);
		printf("%s", prompt);
		return (1);
	}

	return (0);
}

char *find_command(char *command_file, char **path)
{
	int stat_f, i;
	char *command_path;

	command_path = malloc(sizeof(char) * 50);
	stat_f = access(command_file, X_OK);
	i = 0;

	if (stat_f == 0)
		command_path = command_file;

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

		command_path = NULL;
	}

	return (command_path);
}

/**
* check_exit - checks if the command is exit
* @command_file: the command
*
* Return: 1 if true, otherwise 0
*/
int check_exit(char *command_file)
{
	int i;
	char *exit_comm;

	i = 0;
	exit_comm = "exit";

	while (i < 5)
	{
		if (*(command_file + i) != *(exit_comm + i))
			return (0);

		i++;
	}

	return (1);
}

/**
* check_hsh - checks if the command is hsh
* @command_file: the command
*
* Return: 1 if true, otherwise 0.
*/
int check_hsh(char *command_file)
{
	int i;
	char *hsh_comm;

	i = 0;
	hsh_comm = "./hsh";

	while (i < 6)
	{
		if (*(command_file + i) != *(hsh_comm + i))
			return (0);

		i++;
	}

	return (1);
}

/*
* create_child - creates a child process
* @child_pid: pid_t to store the pid
*
* Return: Always Void
*
void create_child(pid_t *child_pid)
{
	*child_pid = fork();

	if (*child_pid == -1)
	{
		handle_error(errno);
		exit(1);
	}
}
*/
/**
* handle_error - handles errors
* errorno: the error number
* @command_name: the command name
*
* Return:
*/

/**
* power - give the power of the number
* @a: number to be powered
* @b: the power
*
* Return: result of the power
*/

/**
* check_exit - checks if the command is exit
* @command_file: the command
*
* Return: 1 if true, otherwise 0
*/
int check_printenv(char *command_file)
{
	int i;
	char *printenv_comm;

	i = 0;
	printenv_comm = "env";

	while (i < 4)
	{
		if (*(command_file + i) != *(printenv_comm + i))
			return (0);

		i++;
	}

	return (1);
}



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
