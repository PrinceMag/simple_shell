#include "shell.h"

int main(int argCount, char **argVector, char **envVal)
{
    if (argCount == 1)
    {
        cmdPrompt(argVector, envVal);
    }

    return 0;
}