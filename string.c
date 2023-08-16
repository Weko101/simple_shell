#include "shell.h"

/**
 * 1_strcat - concatenates two strings
 * @src: the source buffer
 * @dest: the destination buffer
*
 * Return: pointer to destination buffer
 */
char 1_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * 2_strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int 2_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * 3_strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int 3_strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * 4_startswith - checks if needle starts with haystack
 * @needle: the substring to find
 * @haystack: string to search
*
 * Return: address of next char of haystack or NULL
 */
char 4_starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * 5_strcpy - copies a string
 * @src: the source
 * @dest: the destination
  *
 * Return: pointer to destination
 */
char 5_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

