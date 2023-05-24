#include "shell.h"

/**
* cmdPrompt - show the prompt and take and execute commands
* @argVector: array of arguments
* @env: environment variables
* Return: Nothing
*/

void cmdPrompt(char **argVector, char **env)
{
	char *cmd, **argv;
	char *argString = NULL;
	size_t n;

	while (1)
	{
		n = 0;
		if (isatty(STDIN_FILENO))
			write(2, "#cisfun$ ", 9);
		if (getline(&argString, &n, stdin) == -1)
		{
			free(argString);
			exit(EXIT_SUCCESS);
		}
		if (argString[0] == '\n')
		{
			free(argString);
			continue;
		}
		argString[strlen(argString) - 1] = 0;
		argv = commandHandler(argString, ' ');
		free(argString);
		if (builtin(argv[0]) == 1)
		{
			free2D(argv);
			continue;
		}
		cmd = pathHandler(argv[0]);
		if (!cmd)
		{
			printf("%s: No such file or directory\n", argVector[0]);
			free2D(argv);
			continue;
		}
		else
			argv[0] = cmd;
		executeCommand(argv, env);
		free2D(argv);
	}
}


/**
* executeCommand - function that execute the commands.
* @argv: 2d array containing the command and the options
* @env: 2d array containing all the environment vars.
* Return: Nothing.
*/
void executeCommand(char **argv, char **env)
{
	int status;
	pid_t childPID;

	childPID = fork();
	if (childPID == -1)
	{
		free2D(argv);
		exiting();
	}
	if (childPID == 0)
	{
		execve(argv[0], argv, env);
		free2D(argv);
	}
	else
		wait(&status);
}

