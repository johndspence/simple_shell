#include "shell_hdr.h"

int str_len(char *s)
    {
    int i;
    i = 0;

    while (s[i] != '\0')
    {
        while (((s[i] >= '0') && (s[i] <= '9')) || ((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z')))
        {
            i++;
        }
        while (s[i] == ' ')
        {
            ;
        }
        i++;
    }
    printf("string to wordd str_len =%d\n", i);
    return (i);
}

char **str_tok(char *s)
{
    int len;
    int str_position;
    int token;
    int token_position;
    char **tokens;

    str_position = 0;
    token = 0;
    token_position = 0;
    len = str_len(s);
    tokens = malloc(len * sizeof(char));

    printf("string length is %d\n", len);

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
