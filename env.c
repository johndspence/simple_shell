#include "shell_hdr.h"

/**
 * _env - prints environment variables
 * @env: array of env variables
 *
 *
 * Return: 1.
 */
int _env(char **env)
{
	int i;

	i = 0;
	while (env[i] != '\0')
	{
		_printf(env[i]);
		_printf("\n");
		i++;
	}
	return (1);
}
