#include "shell_hdr.h"

char *_getline()
{
    char *line_ptr;
    size_t buf_size;
    int line_len;
    /*int i;*/

    line_ptr = NULL;
    buf_size = 0;
    line_len = getline(&line_ptr, &buf_size, stdin);

    if (line_len == -1)
    {
        _printf("nothing entered\n");
        free(line_ptr);
        exit(EXIT_SUCCESS);
    }
    /*i = 0;
    while (line_ptr[i] != '\0')
    {
        if (line_ptr[i] == '\n')
        {
            line_ptr[i] = '\0';
        }
        i++;
    }*/
    return line_ptr;
}
