#include "shell_hdr.h"

int exec_bltins(char **tokens, char **env, int status, char *line)
{

    if (strings_compare(tokens[0], "exit") == 0)
    {
        return exit_shell(tokens, line);
    }
    else if (strings_compare(tokens[0], "env") == 0)
    {
        return print_env(env);
    }
    else if (strings_compare(tokens[0], "$?") == 0)
    {
        printf("%d\n", status);
    }
    else if (strings_compare(tokens[0], "$$") == 0)
    {
        printf("%d\n", getpid());
    }
    else (exec_programs(tokens));
    return 1;
}