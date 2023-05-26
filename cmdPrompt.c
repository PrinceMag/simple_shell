#include "shell.h"

/**
* cmdPrompt - show the prompt and take and execute commands
* @argVector: array of arguments
* @env: environment variables
* Return: Nothing
*/

void executeCommand(char **argv, char **env);
void cmdPrompt(char **argVector, char **env)
{
	char *cmd, **argv;
	char *argString = NULL;
	size_t n;
	bool fromPipe = false;

	while (1 & !fromPipe)
	{
		n = 0;
		/*check if user input is piped into the program or enetered from terminal*/
		if (isatty(STDIN_FILENO) == 0)
		{
			fromPipe = true;
		}
		
		/*print the $ on the terminal*/
		write(2, "$ ", 2);

		if (getline(&argString, &n, stdin) == -1)
			free(argString);
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
			perror(argVector[0]);
			free2D(argv);
			continue;
		}
		else
			argv[0] = cmd;
		executeCommand(argv, env);
		free2D(argv);
	}
}

void executeCommand(char **argv, char **env)
{
	int status;
	pid_t childPID;
	childPID = fork();
	if (childPID == -1)
	{
		free2D(argv);
		return;
	}
	if (childPID == 0)
	{
		execve(argv[0], argv, env);
		free2D(argv);
		return;
	}
	else
		wait(&status);
}

