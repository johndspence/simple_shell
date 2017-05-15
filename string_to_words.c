#include "shell_hdr.h"

int count_tokens(char *line)
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
        /*else w[i][j] = ' ';*/
    }
    tokens[token] = NULL;
    return tokens;
  }
