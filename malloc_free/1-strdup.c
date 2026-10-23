#include "main.h"
#include <stdlib.h>

/**
 * _strdup - creates a copy of a string in newly allocated memory
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *copy;
	unsigned int length;
	unsigned int index;

	if (str == NULL)
		return (NULL);

	length = 0;
	while (str[length] != '\0')
		length++;

	copy = malloc((length + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);

	index = 0;
	while (index <= length)
	{
		copy[index] = str[index];
		index++;
	}

	return (copy);
}
