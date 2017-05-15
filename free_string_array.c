#include "shell_hdr.h"

void free_string_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
    {
        free (array[i]);
        i++;
    }
    free (array);
    /*exit (0);*/
}
