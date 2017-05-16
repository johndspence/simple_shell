#include "shell_hdr.h"

int exec_bltins(char **tokens, char **env, int status, char *line)
{
    if (tokens[0] == NULL)
    {
        free(tokens);
        free(line);
        return (1);
    }
    else if (strings_compare(tokens[0], "exit") == 0)
    {
        exit_shell(tokens, line);
    }
    else if (strings_compare(tokens[0], "env") == 0)
    {
        free(tokens);
        free(line);
        return print_env(env);
    }
    else if (strings_compare(tokens[0], "$?") == 0)
    {
        free(tokens);
        free(line);
        printf("%d\n", status);
    }
    else if (strings_compare(tokens[0], "$$") == 0)
    {
        free(tokens);
        free(line);
        printf("%d\n", getpid());
    }
    else
    {
        exec_programs(tokens);
    }
    return 1;
}
