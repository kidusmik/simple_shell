#include "hsh.h"

/**
* _strcat - concatenates two strings
* @path: the path string
* @command: the command
* @command_path: the string to store the concatenation
*
* Return: Always void
*/
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

/**
* _strdup - duplicates a string
* @from: the string to be duplicated
*
* Return: ponter to the duplicated string
*/
char *_strdup(char *from)
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

/**
* _strcmp - compares two strings
* @string1: the first string
* @string2: the second string
*
* Return: 1 if true, otherwise 0
*/
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
