#include "shell_hdr.h"

/**
 * _strlen - Determines the length of a string.
 *
 * @string: String to be measured.
 *
 * Return: Length (int).
 */
int _strlen(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		;
	}
	return (i);
}
