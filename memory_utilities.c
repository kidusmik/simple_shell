#include "hsh.h"

/**
* free_ptrs - free pointer memories
* @ptr1: pointer 1
* @ptr2: pointer 2
* @ptr3: pointer 3
*
* Return: Always void
*/
void free_ptrs(char *ptr1, char *ptr2, char *ptr3)
{
	free(ptr1);
	free(ptr2);
	free(ptr3);
}

/**
* free_dptr - free double pointer memories
* @dptr1: double pointer 1
* @dptr2: double pointer 2
* @size: size of the double pointers
*
* Return: Always void
*/
void free_dptr(char **dptr1, char **dptr2, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(dptr1[i]);
		free(dptr2[i]);
		i++;
	}
	free(dptr1);
	free(dptr2);
}
