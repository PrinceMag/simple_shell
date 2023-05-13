#include "shell.h"

/**
* cmdPrompt - show the prompt and take and execute commands
* @argVector: array of arguments
* @envVal: environment variables
* Return: Nothing
*/

void cmdPrompt(char **argVector, char **env)
{
	char *argString = NULL;
	int status;
	ssize_t strLen;
	size_t n = 0;
	char **argv;
	pid_t childPID;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		strLen = getline(&argString, &n, stdin);
		if (strLen == -1)
		{
			free(argString);
			exit(EXIT_FAILURE);
		}

		argString[strlen(argString) - 1] = 0;

		argv = commandHandler(argString, ' ');

		childPID = fork();
		if (childPID == -1)
		{
			free(argString);
			free2D(argv);
			exit(EXIT_FAILURE);
		}

		if (childPID == 0)
		{
			if (execve(argv[0], argv, env) == - 1)
			{
				printf("%s: No such file or directory\n", argVector[0]);
				free2D(argv);
			}
		}
		else
			wait(&status);
	}
}
