#include "shell.h"
int main(void)
{
	char **argv;
	int i = 0;
	char str[] = "cp ./helloworld ../hello/";
	argv = commandHandler(str, ' ');
	for (i = 0; argv[i]; i++)
	{
		printf("%s\n", argv[i]);
	}


	return EXIT_SUCCESS;
}
