#include "shell_hdr.h"

char *_strcat(char *dest, char *src)
{
	size_t i;
	size_t len;

	len = _strlen(dest);
	for (i = 0; src[i]; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
printf("DEST= %s\n", dest);
	return (dest);
}
