#include "shell.h"

/**
* free2D - free a 2d array
* @arr2D: pointer to a 2d array
* Return: nothing.
*/

void free2D(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void exiting()
{
	exit(0);
}

void env()
{
	int i = 0;
	while (__environ[i])
	{
		printf("%s\n", __environ[i]);
		i++;
	}
}
