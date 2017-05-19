#include "shell_hdr.h"

/**
 * _strncmp - Compares the value of two strings, for n chars.
 *
 * @string_a: First string.
 * @string_b: econd string.
 * @n: Number of chars to compare.
 *
 * Return: 1 if not equal, zero if equal (int).
 */
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
