#include "shell_hdr.h"

int print_env(char **env)
{
    int i;

    i = 0;
    while (env[i] != '\0')
    {
        printf("%s\n", env[i]);
        i++;
    }
    return(1);
}
