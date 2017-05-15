#include "shell_hdr.h"

char *get_line()
{
    char *line_ptr;
    size_t buf_size;
    int line_len;

    line_ptr = NULL;
    buf_size = 0;

    line_len = getline(&line_ptr, &buf_size, stdin);
    printf ("line length is %lu\n", (unsigned long int) line_len);

    if (line_len == -1)
    {
        printf("nothing entered\n");
        free(line_ptr);
        exit(EXIT_SUCCESS);
    }
    return line_ptr;
}
