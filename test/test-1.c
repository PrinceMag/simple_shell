#include "../shell.h"
#include <sys/stat.h>



int main(int argc, char **argv)
{
	char *path;
	char **dirs = NULL;
	char *token;
	unsigned int idx = 0;
	struct stat sb;
	char *pwd = getcwd(NULL, 0);

	while (environ[idx])
	{
		if (strncmp(environ[idx], "PATH", 4) == 0)
		{
			path = strdup(environ[idx]);
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
	idx = 0;


	while (dirs[idx])
	{
		chdir(dirs[idx]);
		if (stat(argv[0], &sb) == 0)
		{
			argv[0] = strcat(dirs[idx], argv[0]);
			break;
		}
		idx++;
	}
	chdir(pwd);
	free2D(dirs);
	free(path);
	free(pwd);

	return EXIT_SUCCESS;
}
