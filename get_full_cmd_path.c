#include "shell_hdr.h"

char *get_full_comd_path(char **tokens, char *env_var_val)
{
    struct stat buffer;
    char **env_var_paths;
    char *full_comd_path_temp;
    char *full_comd_path;
    int i;
    int full_comd_path_len;

    if(stat(tokens[0], &buffer) == 0)
    {
        _printf ("get_full_comd_path: tokens[0] was found!\n");
        return (tokens[0]);
    }
    else
    {
        i = 0;

        env_var_paths = parse_path(env_var_val, ':');
        while (env_var_paths[i])
        {
            full_comd_path_len = _strlen(env_var_paths[i]) + _strlen(tokens[0]) + 2;
            full_comd_path = malloc(sizeof(char) * full_comd_path_len);
            if (!full_comd_path)
        	{
        		_printf ("Error: get_full_comd_path->malloc\n");
        		return (NULL);
        	}
            memset(full_comd_path, 0, full_comd_path_len);
            full_comd_path_temp = _strcat(full_comd_path, env_var_paths[i]);
            full_comd_path_temp = _strcat(full_comd_path, "/");
            full_comd_path_temp = _strcat(full_comd_path, tokens[0]);
            full_comd_path = strdup(full_comd_path_temp);
            free (full_comd_path_temp);
            if(stat(full_comd_path, &buffer) == 0)
            {
                free_str_array(env_var_paths);
                return(full_comd_path);
            }
            free(full_comd_path);
            i++;
        }
        free_str_array(env_var_paths);
    }
    _printf("-simple_shell: ");
    _printf(tokens[0]);
    _printf(": command not found\n");
    return(NULL);
}
