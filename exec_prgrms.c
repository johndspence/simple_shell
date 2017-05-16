#include "shell_hdr.h"

int exec_programs(char **tokens)
{
    char *env_var;
    char *env_var_val;
    char *full_comd_path;
    pid_t pid;
    int status;

    env_var = "PATH";
    env_var_val = get_env_var_val(env_var);
    full_comd_path = get_full_comd_path(tokens, env_var_val);

    printf("exec_programs: env var value is: %s\n", env_var_val);
    printf("exec_programs: tokens[0] is %s\n", tokens[0]);
    printf("exec_programs: full_comd_path is %s\n", full_comd_path);

    if ((pid = fork()) == -1)
    {
        perror("fork");
        free (full_comd_path);
        return (1);
    }
    if (pid == 0)
    {
        printf("I am the son ! %d\n", pid);
        execve (full_comd_path, tokens, environ);
        free (tokens);
        free (env_var_val);
        free (full_comd_path);
    }
    else
    {
        printf("I am the father ! %d\n", pid);
		wait(&status);
        printf("My son process has terminated with the status:%d\n", status);
        free_string_array (tokens);
        free (env_var_val);
        /*free (full_comd_path);*/
    }
    free (full_comd_path);
    return (0);
}
