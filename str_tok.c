#include "shell_hdr.h"
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \n:"

char **str_tok(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;

  if (!tokens)
  {
      fprintf(stderr, "lsh: allocation error\n");
      free(tokens);
      exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL)
  {
      tokens[position] = token;
      position++;

      if (position >= bufsize)
      {
          bufsize += LSH_TOK_BUFSIZE;
          tokens_backup = tokens;
          tokens = realloc(tokens, bufsize * sizeof(char*));
          if (!tokens)
          {
              free(tokens_backup);
              free(tokens);
              fprintf(stderr, "lsh: allocation error\n");
              exit(EXIT_FAILURE);
          }
      }
      token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
return tokens;
}

/*int count_tokens(char* line)
{
    int tok_cnt;
    int i;

    tok_cnt = 0;
    for (i = 0; i < _strlen(line); i++)
    {
        if(line[i] == ' ' || line[i] == '\n')
        {
            tok_cnt++;
        }
    }
    return(tok_cnt);
}

char** str_tok(char* line)
{

    char**tokens;
    int tok_ttl;
    int tokens_iter;

    tokens = NULL;

    tok_ttl = count_tokens(line);

    printf("str_tok: tok_ttl = %d\n", tok_ttl);
    tokens = malloc(sizeof(char **) * (tok_ttl));
    if (tokens == NULL)
    {
        return NULL;
    }
    tokens_iter = 0;
    tokens[0] = strtok(line, " \n:");
    tokens_iter++;
    while (tokens_iter < tok_ttl)
    {
        tokens[tokens_iter] = strtok(NULL, " \n:");
        tokens_iter++;
    }

    return tokens;
}*/