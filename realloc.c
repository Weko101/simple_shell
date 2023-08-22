#include "Shell.h"

/**
 * 1_realloc - reallocates a block of memory
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * @ptr: pointer to previous malloc'ated block
 *
 * Return: pointer to da ol'block nameen
 */
void 1_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

/**
 * 2_memset - fills memory with a constant byte
 * @b: the byte to fill *s with
 * @s: the pointer to the memory area
 * @n: the amount of bytes to be filled
 *
 * Return: (s) a pointer to the memory area s
 */
char 2_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * 3_ffree - frees a string of strings
 * @pp: string of strings
 */
void 3_ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

