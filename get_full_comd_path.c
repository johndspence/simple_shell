#include "shell_hdr.h"

char *get_full_comd_path(char **tokens, char *env_var_val)
{
    struct stat *buffer;
    char **env_var_paths;
    char *full_comd_path;
    int i;
    int full_comd_path_len;

    buffer = malloc(sizeof(struct stat));

    printf("get_full_comd_path: tokens[0] is %s\n", tokens[0]);
    if(stat(tokens[0], buffer) == 0)
    {
        free (buffer);
        printf ("get_full_comd_path: tokens[0] was found!\n");
        return (tokens[0]);
    }
    else
    {
        i = 0;

        printf("get_full_comd_path: entering else statement\n");
        env_var_paths = str_tok(env_var_val);
        while (env_var_paths[i])
        {
            full_comd_path_len = _strlen(env_var_paths[i]) + _strlen(tokens[0]) + 2;
            printf("full_comd_path_len = %d\n", full_comd_path_len);
            full_comd_path = malloc(sizeof(char *) * full_comd_path_len);
            if (!full_comd_path)
        	{
        		printf ("Error: get_full_comd_path->malloc\n");
        		return (NULL);
        	}
            memset(full_comd_path, 0, full_comd_path_len);
            full_comd_path = _strcat(full_comd_path, env_var_paths[i]);
            full_comd_path = _strcat(full_comd_path, "/");
            full_comd_path = _strcat(full_comd_path, tokens[0]);
            printf("get_full_comd_path: path_concat_comd = %s\n", full_comd_path);
            if(stat(full_comd_path, buffer) == 0)
            {
                printf("get_full_comd_path: stat(path_concat_comd, buffer) == 0\n");
                free (buffer);
                /*free_string_array (env_var_paths);*/
                return(full_comd_path);
            }
            i++;
        }
    }
    free (buffer);
    free_string_array (env_var_paths);
    free (full_comd_path);
    return ("/bin/ls");/*FIX THIS!!!*/
}