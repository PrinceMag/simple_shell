#include "shell.h"

/**
* cmdPrompt - show the prompt and take and execute commands
* @argVector: array of arguments
* @envVal: environment variables
* Return: Nothing
*/

void cmdPrompt(char **argVector, char **envVal)
{
	char *lineString = NULL;
	int status;
	ssize_t numChar;
	size_t n = 0;
	char **argVal;
	pid_t childProcessID;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		numChar = getline(&lineString, &n, stdin);
		if (numChar == -1)
		{
			free(lineString);
			exit(EXIT_FAILURE);
		}

		lineString[strlen(lineString) - 1] = 0;

		argVal = commandHandler(lineString, ' ');
		childProcessID = fork();
		if (childProcessID == -1)
		{
			free(lineString);
			exit(EXIT_FAILURE);
		}

		if (childProcessID == 0)
		{
			if (execve(argVal[0], argVal, envVal) == - 1)
				printf("%s: No such file or directory\n", argVector[0]);
		}
		else
			wait(&status);
	}
}
