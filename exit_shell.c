#include "shell_hdr.h"
/**
 * exit_shell - Exits shell.
 * @tokens: Commands received from stdin.
 * @line: Line received from stdin.
 *
 * Return: status (int).
 */
int exit_shell(char **tokens, char *line)
{
	int exit_value;

	exit_value = 0;

	if (tokens[1] != NULL)
	{
		exit_value = string_to_integer(tokens[1]);
	}
	free(tokens);
	free(line);
	exit(exit_value);
}
