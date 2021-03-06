#include "shell_hdr.h"

/**
 * _strdup - duplicate a string.
 * @str: A string to duplicate.
 *
 * Return: The duplicated string.
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		_printf("Error: strdup->malloc\n");
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}
	return (str2);
}
