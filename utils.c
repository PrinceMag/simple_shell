#include "shell.h"

/**
* free2D - free a 2d array
* @arr2D: pointer to a 2d array
* Return: nothing.
*/

void free2D(char **arr2D)
{
	int i;
	for (i = 0; arr2D[i]; i++)
		free(arr2D[i]);

	free(arr2D[i]);
	free(arr2D);
}
