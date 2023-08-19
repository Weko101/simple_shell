#include "shell.h"

/**
 *1_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *
 *Return: the concatenated string
 */
char 1_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 *2_strchr - locates a character in a string
 *@c: the character to look for
 *@s: the string to be parsed
 *
 *Return: (s) a pointer to the memory area s
 */
char 2_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 *3_strncpy - copies a string
 *@n: the amount of characters to be copied
 *@dest: the destination string to be copied to
 *@src: the source string
 *
 *Return: the concatenated string
 */
char 3_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

