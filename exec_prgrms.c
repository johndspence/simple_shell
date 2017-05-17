#include "shell_hdr.h"

int exec_prgrms(char **tokens, char *line)
{
	char *env_var;
	char *env_var_val;
	char *full_comd_path;
	pid_t pid;
	int status;

	env_var = "PATH";
	env_var_val = get_env_var_val(env_var);
	full_comd_path = get_full_comd_path(tokens, env_var_val);

	if (full_comd_path != NULL)
	{
		if ((pid = fork()) == -1)
		{
			perror ("fork");
			free (full_comd_path);
			return (1);
		}
		if (pid == 0)
		{
			if (execve (full_comd_path, tokens, environ) == -1)
			{
				perror (*tokens);
				free (tokens);
				free (env_var_val);
				free (full_comd_path);
				exit (EXIT_FAILURE);
			}
			return (EXIT_SUCCESS);
		}
		wait(&status);
	}
	free (line);
	free (tokens);
	free (env_var_val);
	free (full_comd_path);
	return (0);
}
