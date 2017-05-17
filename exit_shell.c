#include "shell_hdr.h"

int exit_shell(char **tokens, char *line)
{
	int exit_value;

	exit_value = 0;

	if (tokens[1] != NULL)
	{
		exit_value = string_to_integer(tokens[1]);
	}
	free (tokens);
	free (line);
	exit (exit_value);
}
