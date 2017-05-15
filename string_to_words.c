#include "shell_hdr.h"

char **str_tok(char *line)
{
	char **tokens;
	char *token;
	int i, len;

	len = 0;
	for (i = 0; line[i]; i++)
	{
		if (line[i] == ' ' || line[i] == '\n')
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

	token = strtok(line, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}


/*int count_tokens(char *line)
{
    int token_count;

    token_count = 0;
    while (*line != '\0')
    {
        while ((((*line >= '0') && (*line <= '9'))
        || ((*line >= 'a') && (*line <= 'z'))
        || ((*line >= 'A') && (*line <= 'Z')))
        && (*line != '\0'))
        {
            line++;
        }
        while ((*line == ' ') && (*line != '\0'))
        {
            line++;
        }
        token_count++;
    }
    printf("token_count = %d\n", token_count);
    return (token_count);
}

char **str_tok(char *s)
{
    int str_position;
    int token;
    int token_position;
    int token_count;
    char **tokens;

    str_position = 0;
    token = 0;
    token_position = 0;
    token_count = count_tokens(s);
    tokens = malloc(sizeof(char **) * (token_count + 1));

    while (s[str_position] != '\0')
    {
        token_position = 0;

        while (((s[str_position] >= '0') && (s[str_position] <= '9')) ||
        ((s[str_position] >= 'a') && (s[str_position] <= 'z')) ||
        ((s[str_position] >= 'A') && (s[str_position] <= 'Z')))
        {
            tokens[token][token_position] = s[str_position];
            str_position++;
            token_position++;
        }
        tokens[token][token_position] = '\0';
        str_position++;
        token++;
        else w[i][j] = ' ';
    }
    tokens[token] = NULL;
    return tokens;
}*/
