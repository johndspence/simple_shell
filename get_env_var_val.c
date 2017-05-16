#include "shell_hdr.h"
#define BUFFER 128

char *get_env_var_val(char *env_var)
{
    size_t len;
    char *env_var_val;
    int i;
    int j;
    int k;

    len = _strlen(env_var);
    env_var_val = malloc(sizeof(char) * BUFFER);
    if (!env_var_val)
    {
        _printf("Error get_env_var_val->malloc\n");
        free (env_var_val);
        return (NULL);
    }

    for (i = 0; environ[i]; i++)
    {
        if (_strncmp(env_var, environ[i], len) == 0)
            break;
    }
    for (j = len, k = len; j < BUFFER; j++, k++)
    {
        if (environ[i][k] == '=')
        {
            k++;
        }
        env_var_val[j - len] = environ[i][k];
    }
    return (env_var_val);
}
