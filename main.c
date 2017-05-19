#include "shell_hdr.h"

/**
 * main - main function for simple unix shell.
 *
 * @argc: Argument count.
 * @argv: Argument vector.
 * @env: Environment variables.
 *
 * Return: string (char *)
 */
int main(__attribute__((unused)) int argc,
	__attribute__((unused)) char **argv, char **env)
{
	char *line;
	char **tokens;
	int status;

	status = 1;
	tokens = NULL;
	line = NULL;

	signal(SIGINT, sig_handle_ctl_c);
	while (status == 1)
	{
		prompt();
		line = _getline();
		tokens = str_tok(line);
		status = exec_bltins_prgrms(tokens, env, status, line);
	}
	free(tokens);
	return (status);
}

/**
 * sig_handle_ctl_c -Keyboard signal handler to intercept Ctrl-C.
 *
 * @sign: Signal.
 *
 * Return: (void).
 */
void sig_handle_ctl_c(int sign)
{
	char prompt[] = ">>> ";

	signal(sign, SIG_IGN);
	write(1, "\nPlease type 'exit' to quit.\n", 29);
	write(1, prompt, 4);
	signal(SIGINT, sig_handle_ctl_c);
}
