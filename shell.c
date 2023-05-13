#include "shell.h"

int main(int argc, char **argv, char **envVar)
{
    if (argc == 1)
    {
        cmdPrompt(argv, envVar);
    }

    return 0;
}
