#include "shell_hdr.h"

int _strcmp(char *string_a, char *string_b)
{
	int i;
	i = 0;

	while ((string_a[i] == string_b[i]) && string_a[i] != '\0')
	{
		i++;
	}
	if (string_a[i] > string_b[i])
	{
		return (1);
	}
	else if (string_a[i] < string_b[i])
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
