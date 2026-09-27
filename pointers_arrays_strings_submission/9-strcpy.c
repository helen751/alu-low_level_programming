#include "main.h"

/**
 * _strcpy - Copies a string, including its null byte
 * @dest: Buffer that receives the copied string
 * @src: String to copy
 *
 * Return: A pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	do {
		dest[index] = src[index];
		index++;
	} while (src[index - 1] != '\0');

	return (dest);
}
