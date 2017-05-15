#include "shell_hdr.h"
/**
 * op_add - Makes the sum of two numbers
 * @arg1: First operand
 * @arg2: Second operand
 *
 * Description: This is a longer description.
 * Don't forget that a line should not exceed 80 characters.
 * But you're totally free to use several lines to properly
 * describe your function
 * Return: The sum of the two parameters
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv, char**env)
{
    char* line;
    char** tokens;
    int status;
    int i;

    status = 1;
    tokens = NULL;
    line = NULL;

    /*signal(SIGINT, sig_handle_ctl_c);*/
    while(status == 1)
    {

        prompt();
        line = get_line();

        printf ("main.c: you typed %s", line);
        tokens = str_tok(line);
        for (i = 0; tokens[i] != NULL; i++)
        {
            printf ("main.c: token[%d] is %s\n", i, tokens[i]);
        }
        printf("main.c: env[0] is %s\n", env[0]);
        status = exec_bltins(tokens, env, status, line);

    }
    free(line);
    free_string_array(tokens);
    return status;
}

/*void sig_handle_ctl_c(int sign)
{
        char prompt[] = ">>> ";

        signal(sign, SIG_IGN);
        write(1 , "\nPlease type 'exit' to quit.\n", 29);
        write(1, prompt, 4);
        signal(SIGINT, sig_handle_ctl_c);
}*/