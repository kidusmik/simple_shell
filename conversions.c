#include "hsh_main.h"

/**
* len_pid - determines the length of the pid
* @pid: the pid
*
* Return: the length of the pid
*/
int len_pid(pid_t pid)
{
	int i;

	for (i = 0; pid > 0; i++)
	{
		pid = pid / 10;
	}
	return (i);
}

/**
* pid_to_str - converts the pid to string
* @pid: the pid
*
* Return: pointer to the string
*/
char *pid_to_str(pid_t pid)
{
	char *pid_str;
	int len, div, i;

	i = 0;
	div = 1;
	len = len_pid(pid);
	pid_str = malloc(sizeof(char) * len);

	for (; pid / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		*(pid_str + i) = '0' + (pid / div);
		pid %= div;
		div /= 10;
		i++;
	}
	*(pid_str + i) = '\0';
	return (pid_str);
}

/**
* str_to_pid - converts the string formatted pid to pid_t
* @pid_str: the pid in string format
*
* Return: the converted pid_t pid
*/
pid_t str_to_pid(char *pid_str)
{
	char *pid_str_ptr;
	int len, digit;
	pid_t result;
	
	result = 0;
	pid_str_ptr = pid_str;
	len = 0;

	while (*pid_str_ptr)
	{
		len++;
		pid_str_ptr = pid_str_ptr + 1;
	}
	pid_str_ptr = pid_str;
	len = len - 1;

	while (len >= 0)
	{
		digit = char_to_int(pid_str_ptr);
		result = result + (digit * power(10, len));
		pid_str_ptr = pid_str_ptr + 1;
		len--;
	}

	return (result);
}

/**
* char_to_int - converts the chars to their equivalent ints
* @ch: the character
*
* Return: the int converted char
*/
int char_to_int(char *ch)
{
	if (*ch == '0')
		return (0);
	else if (*ch == '1')
		return (1);
	else if (*ch == '2')
		return (2);
	else if (*ch == '3')
		return (3);
	else if (*ch == '4')
		return (4);
	else if (*ch == '5')
		return (5);
	else if (*ch == '6')
		return (6);
	else if (*ch == '7')
		return (7);
	else if (*ch == '8')
		return (8);
	else if (*ch == '9')
		return (9);

	return (-1);
}

/**
* _strlen - find the string length
* @str: the string
*
* Return: the length
*/
int _strlen(char *string)
{
	int length;

	length = 0;
	while (*string != '\0')
	{
		length++;
		string = string + 1;
	}

	return (length - 1);
}
