#include "shell_hdr.h"

int _strcmp(char *string_a, char *string_b)
{
    int i;

    i = 0;
    while (string_a[i] == string_b[i])
        {
            if (string_a[i] == '\0' || string_b[i] == '\0')
            {
                break;
            }
            i++;
        }
    if (string_a[i] == '\0' && string_b[i] == '\0')
    {
        return (0);
    }
    else
    {
        return (-1);
    }
}
