#include "shell.h"

/**
* commandHandler - splits the command that the user provide into
* multiple token 
* Description: e.g ("cp test ../folder/" 
*  OUTPUT: 	cp
*  			test
*  			../folder/)
* @strArg: the command line provided by the user
* @delim: the delimiter (in our case it's always space)
* Return: 2d array contains the tokens
*/


char **commandHandler(const char *strArg, char delim)
{
	char **argv;
	size_t count;
	char *tmpStr;
	size_t idx;
	char *token;
	char *delimiter;

	if (!strArg)
		return (NULL);

	idx = 0;
	count = 0;
	tmpStr = (char *) strArg;
	while (*tmpStr != 0)
	{
		if (delim == *(tmpStr++))
			count++;
	}
	count++;

	argv = (char **)malloc(sizeof(char *) * count);
	if (!argv)
		return (NULL);

	delimiter = &delim;
	tmpStr = (char *) strArg;
	token = strtok(tmpStr, delimiter);

	while (token)
	{
		argv[idx++] = strdup(token);
		token = strtok(0, delimiter);
	}

	argv[idx] = 0;

	return (argv);
}
