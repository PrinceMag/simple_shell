#include "shell.h"

/**
* free2D - free a 2d array
* @arr: pointer to a 2d array
* Return: nothing.
*/

void free2D(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}


/**
* exiting - builtin function for exit
* Return: nothing
*/
void exiting(void)
{
	exit(0);
}

/**
* env - builtin function for env function.
* Description: prints out all the environment vars
* Return: nothing
*/
void env(void)
{
	int i = 0;

	while (__environ[i])
	{
		printf("%s\n", __environ[i]);
		i++;
	}
}
