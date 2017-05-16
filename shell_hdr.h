#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

void prompt(void);
char *_getline(void);
char **str_tok(char* line);
int count_chars(char* line, char space);
int count_tokens(char* line);
int exec_bltins_prgrms(char **tokens, char **env, int status, char *line);
int exit_shell(char **tokens, char *line);
int _env(char **env);
int exec_prgrms(char **tokens);
int _strlen(char *string);
int _strcmp(char *string_a, char *string_b);
int _strncmp(const char *string_a, const char *string_b, size_t n);
char *_strcat(char *dest, char *src);
char *get_env_var_val(char *env_var);
char *get_full_comd_path(char **tokens, char *env_var_val);
void free_str_array(char **array);
char **parse_path(char *line, char);
int count_chars(char *s1, char seperator);
int count_words(char *s, char seperator);

void sig_handle_ctl_c(int sign);


#endif
