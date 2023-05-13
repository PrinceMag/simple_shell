#include "shell.h"

/**
* cmdPrompt - show the prompt and take and execute commands
* @argVector:
* @envVal:
* Return: Nothing
*/

void cmdPrompt(char **argVector, char **envVal)
{
	char *lineString = NULL;
	/* We don't need that var anymore*/
	/*int lineStringIndex;*/
	int status;
	ssize_t numChar;
	size_t n = 0;
	char *argVal[] = {NULL, NULL};
	pid_t childProcessID;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("cisfun$ ");

		numChar = getline(&lineString, &n, stdin);
		if (numChar == -1)
			free(lineString), exit(1);

		lineString[strlen(lineString) - 1] = 0;
		/* I replace this part of code with only that line*/
		/*
		lineStringIndex = 0;
		while (lineString[lineStringIndex] != 0)
		{
			if (lineString[lineStringIndex] == '\n')
			{
				lineString[lineStringIndex] = 0;
			}
			lineStringIndex++;
		}
		*/

		argVal[0] = lineString;
		if ((childProcessID = fork()) == -1)
			free(lineString), exit(1);

		if (execve(argVal[0], argVal, envVal) - 1)
			printf("%s: No such file or directory\n", argVector[0]);
		else
			wait(&status);
	}
}
