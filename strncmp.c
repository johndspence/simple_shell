#include "shell_hdr.h"

int _strncmp(const char *string_a, const char *string_b, size_t n)
{
	while (n > 0 && *string_a == *string_b && *string_a != '\0')
	{
		++string_a;
		++string_b;
		--n;
	}
	if (n == 0 || *string_a == *string_b)
	{
		return (0);
	}
	return (1);
}
