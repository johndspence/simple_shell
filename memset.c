#include "shell_hdr.h"

/**
 * mem_set - fills memory with a constant char
 * @mem: Memory area to initialize.
 * @byte: Constant byte.
 * @n: Number of bytes to initialize.
 *
 * Return: Void.
 */
void mem_set(void *mem, int byte, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		*((char *)mem + i) = byte;
	}
}
