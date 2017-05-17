#include "shell_hdr.h"

char *_getline()
{
	char *line_ptr;
	size_t buf_size;
	int line_len;
	int i;

	line_ptr = NULL;
	buf_size = 0;
	line_len = getline(&line_ptr, &buf_size, stdin);

	if (line_len == -1)
	{
		_printf("nothing entered\n");
		free(line_ptr);
		exit(EXIT_SUCCESS);
	}
	printf("%d\n", line_len);
	for (i = 0; line_ptr[i] != '\0'; i++)
	{
		printf("%d ", i);
		printf("getline: line_ptr %c\n", line_ptr[i]);
	}
	/*line_ptr[line_len - 1] = '\0';*/
	return line_ptr;
}
