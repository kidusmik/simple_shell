#include "hsh.h"

void _strcat(char *path, char *command, char *command_path)
{
	int i, j;

	i = 0;
	j = 0;

	while (*(path + i) != '\0')
	{
		*(command_path + i) = *(path + i);
		i++;
	}
	*(command_path + i) = '/';
	i++;

	while (*(command + j) != '\0')
	{
		*(command_path + i) = *(command + j);
		i++;
		j++;
	}
	*(command_path + i) = '\0';
}

char * _strdup(char *from)
{
	int i, len;
	char *dup_str;

	len = _strlen(from) + 1;
	dup_str = malloc(sizeof(int) * len);
	i = 0;

	while (*(from + i) != '\0')
	{
		*(dup_str + i) = *(from + i);
		i++;
	}
	*(dup_str + i) = '\0';

	return (dup_str);
}

int _strcmp(char *string1, char *string2)
{
	int i;

	i = 0;

	while (*(string1 + i) != '\0')
	{
		if (*(string1 + i) != *(string2	+ i))
			return (0);

		i++;
	}

	return (1);
}	
