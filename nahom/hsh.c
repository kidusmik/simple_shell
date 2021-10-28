#include "hsh.h"

/**
 * main - main entry point
 * @ac: number of argument
 *
 */
int main(int ac, char *av[], char **env)
{
	// load config file if exits and define variables
	(void)ac;
	int execution_counter = 1;
	int status = 0;

	/* 
	- Run command loop
	- before that check the initialization command. 
			- initialize the shell, only the program name is accepted
			  passing an argument is not accepted.
	*/
	if (ac > 1)
	{
		char err_msg[100];

		sprintf(err_msg, "%s: 0: Can't open %s\n", av[1], av[1]);
		write(2, err_msg, strlen(err_msg));

		return (0);
	}

	status = hsh_loop(av, execution_counter, env);
	return (status);
}
