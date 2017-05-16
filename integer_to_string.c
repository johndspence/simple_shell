#include "shell_hdr.h"

char *integer_to_string(int n)
{
    int i;
    int len;
    int neg;
    char *str;
    if (n == 0)
    {
        return ("0");
    }
    else if (n < 0)
    {
        neg = 1;
    }
    else
    {
        neg = 0;
        n = n * -1;
    }
    len = integer_length(n);
    str = malloc(sizeof(char) * (len + neg + 1));
    if (str == NULL)
    {
        return NULL;
    }
    str[len + neg] = '\0';
    for (i = 1; i <= len; i++)
    {
        str[len + neg - i] = '0' + (n % 10 * -1);
        n = n / 10;
    }
    if (neg)
        str[0] = '-';
    return str;
}
