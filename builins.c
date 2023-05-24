#include "shell.h"

#define SUCCESS 1
#define FAILURE -1
/**
* builtin - check if there are some builtin funtions
* and execute them.
* @arg: function name.
* Return: 1 On Success, -1 Othewise
*/

int builtin(char *arg)
{
	builin_t bin[] = {
		{"exit", exiting},
		{"env", env},
		{NULL, NULL},
	};
	int x;

	x = 0;
	while (bin[x].name)
	{
		if (strcmp(arg, bin[x].name) == 0)
		{
			bin[x].func();
			return (SUCCESS);
		}
		x++;
	}
	return (FAILURE);
}
