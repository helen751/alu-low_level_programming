#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings in newly allocated memory
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *result;
	unsigned int length1;
	unsigned int length2;
	unsigned int index;

	length1 = 0;
	if (s1 != NULL)
	{
		while (s1[length1] != '\0')
			length1++;
	}

	length2 = 0;
	if (s2 != NULL)
	{
		while (s2[length2] != '\0')
			length2++;
	}

	result = malloc((length1 + length2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	index = 0;
	while (index < length1)
	{
		result[index] = s1[index];
		index++;
	}

	index = 0;
	while (index < length2)
	{
		result[length1 + index] = s2[index];
		index++;
	}
	result[length1 + length2] = '\0';

	return (result);
}
