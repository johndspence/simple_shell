#include "shell_hdr.h"

char **parse_path(char *line)
{
	char **tokens;
	char *token;
	int i, len;

	len = 0;
	for (i = 0; line[i]; i++)
	{
		if (line[i] == ':')
		{
			len++;
		}
	}
	len++;

	tokens = malloc(sizeof(char *) * len);
	if (!tokens)
	{
		printf("Error: malloc - parse_line\n");
		return (NULL);
	}
	token = strtok(line, ":");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, ":");
	}
	return (tokens);
}
