#include "shell_hdr.h"

/**
 * integer_length - Determines number of chars for an integer representation.
 *
 * @n: Integer to be evaluated.
 *
 * Return: Number of chars.
 */
int integer_length(int n)
{
	int i;

	for (i = 0; n <= -1; i++)
	{
		n = n / 10;
	}
	return (i);
}
