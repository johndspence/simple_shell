#include "shell_hdr.h"

int print_char(char c)
{
    return (write(1, &c, 1));
}

void _printf(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        print_char(str[i]);
    }
}
