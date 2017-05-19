#include "shell_hdr.h"

/**
 * exec_bltins_prgrms - Executes shell builtins and calls programs.
 * @tokens: Commands received from stdin.
 * @env: environment variable array.
 * @status: return value
 * @line: command line input.
 *
 * Return: status (int).
 */
int exec_bltins_prgrms(char **tokens, char **env, int status, char *line)
{
	char *int_to_str;

	if (tokens[0] == NULL)
	{
		free(tokens);
		free(line);
		return (1);
	}
	else if (_strcmp(tokens[0], "exit") == 0)
		exit_shell(tokens, line);
	else if (_strcmp(tokens[0], "env") == 0)
	{
		free(tokens);
		free(line);
		return (_env(env));
	}
	else if (_strcmp(tokens[0], "$?") == 0)
	{
		free(tokens);
		free(line);
		int_to_str = integer_to_string(status);
		_printf(int_to_str);
		_printf("\n");
		free(int_to_str);
	}
	else if (_strcmp(tokens[0], "$$") == 0)
	{
		free(tokens);
		free(line);
		int_to_str = integer_to_string(getpid());
		_printf(int_to_str);
		_printf("\n");
		free(int_to_str);
	}
	else
		exec_prgrms(tokens, line);
	return (1);
}
