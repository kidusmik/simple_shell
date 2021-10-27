#include "hsh.h"

int line_input_check(char **input_buffer, size_t *b_size, FILE *stream, ssize_t *chk_line)
{
	ssize_t line;

	line = getline(input_buffer, b_size, stream);

	if (line == EOF || line == -1)
	{
		*chk_line = 1;
		return (1);
	}

	return (0);
}
	
