#include "../shell.h"

int main(void)
{
	char cmd[] = "/bin/cp";
	struct stat sb;
	if (stat(cmd, &sb) == 0)
	{
		return 0;
	}
	perror("cmd not found");
	return EXIT_SUCCESS;
}
