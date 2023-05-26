#include "../shell.h"

int main(void)
{
	char *cmd;
	char str[] = "clear";
	cmd = pathHandler(str);
	free(cmd);
	return EXIT_SUCCESS;
}
