#include "shell_hdr.h"

/**
 * print_char - Prints a single char to stdout.
 *
 * @c: Char to print.
 *
 * Return: write stdlib execution (int)
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Prints a string char to stdout.
 *
 * @str: String to print.
 *
 * Return: (void)
 */
void _printf(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		print_char(str[i]);
	}
}
