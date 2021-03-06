#include "shell_hdr.h"

/**
 * _getline - Retrieves commands from stdin.
 *
 * Return: Command line input.
 */
char *_getline()
{
	char *line_ptr;
	size_t buf_size;
	int line_len;

	line_ptr = NULL;
	buf_size = 0;
	line_len = getline(&line_ptr, &buf_size, stdin);

	if (line_len == -1)
	{
		_printf("nothing entered\n");
		free(line_ptr);
		exit(EXIT_SUCCESS);
	}
	return (line_ptr);
}
