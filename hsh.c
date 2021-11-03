#include "hsh.h"

/**
 * main - main entry point
 * @ac: number of argument
 * @av: argument value
 * @env: environment value
 * Return: status
 */
int main(int ac, char *av[], char **env)
{
	/* load config file if exits and define variables */

	int execution_coun = 1;
	int status = 0;
	(void)ac;

	if (ac > 1)
	{
		char err_msg[100];

		sprintf(err_msg, "%s: 0: Can't open %s\n", av[1], av[1]);
		write(2, err_msg, strlen(err_msg));

		return (0);
	}

	status = hsh_loop(av, execution_coun, env);
	return (status);
}
