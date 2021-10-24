#include "main.h"

/**
* run_parent_shell - runs the parent shell
*
* Return: 0 for success, 1 otherwise
*/
int run_parent_shell(void)
{
	char *buffer, *delim, *params, *prompt;
	char *argv[2];
	size_t b_size;
	int status;
	pid_t child_pid;
	struct stat st;

	argv[1] = NULL;
	b_size = 32;
	buffer = malloc(sizeof(char) * b_size);
	delim = "\n";
	prompt = "$ ";

	printf("%s", prompt);

	while (getline(&buffer, &b_size, stdin) != -1)
	{
		params = strtok(buffer, delim);
		argv[0] = params;

		if (check_exit(argv[0]))
			exit(0);

		if (check_command(argv[0], &st, prompt))
			continue;

		child_pid = fork();

		if (child_pid == -1)
			return (1);

		if (child_pid == 0)
		{
			if (check_hsh(argv[0]))
                        	run_child_shell();
			if (execve(argv[0], argv, NULL) == -1)
				return (1);
		}
		else
		{
			wait(&status);
			printf("%s", prompt);
		}
	}

	return (0);
}
