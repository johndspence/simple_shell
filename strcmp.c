#include "shell_hdr.h"

/**
 * _strcmp - Compares ther value of two strings..
 *
 * @string_a: First string.
 * @string_b: Second string.
 *
 * Return: 1 if a > b or a < b, 0 if equal (int).
 */
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
