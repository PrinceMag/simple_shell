#include "shell.h"

void free2Darr(char **arr, unsigned int count);
char  *pathHandler(char *arg)
{
	char *path, *token, *cmd, *pwd;
	char **dirs = NULL;
	unsigned int idx, count;
	struct stat sb;
	char buf[BUFF_SIZE];

	idx = 0;
	while (__environ[idx])
	{
		if (strncmp(__environ[idx], "PATH", 4) == 0)
		{
			path = strdup(__environ[idx]);
			break;
		}
		idx++;
	}
	idx = 0;
	token = strtok(&path[5], ":");
	while (token)
	{
		dirs = realloc(dirs, (idx + 1) * sizeof(char *));
		dirs[idx] = strdup(token);
		token = strtok(NULL, ":");
		idx++;
	}
	count = idx, idx = 0;
	pwd = getcwd(buf, BUFF_SIZE), cmd = NULL;
	while (dirs[idx])
	{
		chdir(dirs[idx]);
		if (stat(arg, &sb) == 0)
		{
			cmd = strdup(dirs[idx]);
			strcat(cmd, "/");
			strcat(cmd, arg);
			break;
		}
		idx++;
	}
	chdir(pwd);
	free(path);
	free2Darr(dirs, count);
	return (cmd);
}

/**
* free2Darr - free a 2d array
* @arr: pointer to a 2d array
* @count: length of the arr
* Return: nothing.
*/

void free2Darr(char **arr, unsigned int count)
{
	unsigned int i = 0;
	for (i = 0; i < count; i++)
		free(arr[i]);

	free(arr);
}

