#include "shell_hdr.h"

int exit_shell(char **tokens, char *line)
{
    int exit_value;

    exit_value = 0;

    printf ("match on exit\n");
    if (tokens[1] != NULL)
    {
        exit_value = atoi(tokens[1]);
    }
    free (tokens);
    free (line);
    exit(exit_value);
}
