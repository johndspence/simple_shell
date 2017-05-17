#include "shell_hdr.h"

int string_to_integer(char *string)
{
	int i;
	int val;
	int sign;

	sign = 1;
	val = 0;
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '-' && !val)
		{
			sign = sign * -1;
		}
		else if (string[i] == '+' && !val)
		{
			sign = sign * 1;
		}
		else if (string[i] > '9' || string[i] < '0')
		{
			return 0;
		}
		else
		{
			val = (val * 10) + (string[i] - '0');
		}
	}
	return (val * sign);
}
