#include "hsh.h"
/**
 * new_process - This function create a child process and executes
 * @av: Pointer to an array of strings with all arguments of input buffer
 * @execution_counter: Executions counter in each postiion.
 * @env: Enviroment variable.
 * Return: void
 **/
int new_process(char *av[], int execution_counter, char **env)
{
	char *path = NULL, *file = NULL, err_msg[100];
	int status = 0, found = 0, alloc = 0, exit_status = 0;
	pid_t child_pid;
	struct stat st;

	/* query info about the file */
	if (stat(av[1], &st) == 0)
		found = 1, file = av[1];
	else
	{
		path = _getenv("PATH", env), file = check_file(path, av[1]);
		if (file != NULL)
			found = 1, alloc = 1;
		free(path);
	}
	if (found)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if ((execve(file, (av + 1), env)) == -1)
			{
				sprintf(err_msg, "%s: %d: %s: not found\n", av[0], execution_counter, av[1]);
				write(2, err_msg, _strlen(err_msg));
				(alloc == 1) ? free(file) : (void)alloc;
			}
		}
		waitpid(child_pid, &status, 0), (alloc == 1) ? free(file) : (void)alloc;
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			return (exit_status);
		}
	}
	else
	{
		sprintf(err_msg, "%s: %d: %s: not found\n", av[0], execution_counter, av[1]);
		write(2, err_msg, _strlen(err_msg));
		return (127);
	}
	return (0);
}

/**
 * check_file - check if the filename exist in directory.
 * @full_path: All enviroment varible PATH
 * @file: file name
 * Return: file path || file || NULL
 **/
char *check_file(char *full_path, char *file)
{
	struct stat st;
	char *path_name;
	char *token = NULL;
	int i = 0;

	token = strtok(full_path, ":");
	while (token != NULL)
	{
		path_name = malloc((_strlen(token) + _strlen(file) + 2) * sizeof(char));
		if (path_name == NULL)
		{
			free(path_name);
			return (file);
		}
		_strcpy(path_name, token);
		_strcat(path_name, "/");
		_strcat(path_name, file);
		if (stat(path_name, &st) == 0)
		{
			return (path_name);
		}
		free(path_name);
		token = strtok(NULL, ":");
		i++;
	}
	return (NULL);
}
