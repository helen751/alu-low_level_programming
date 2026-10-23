#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array and initializes it with a character
 * @size: number of characters in the array
 * @c: character used to initialize the array
 *
 * Return: pointer to the array, or NULL if size is 0 or allocation fails
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);

	array = malloc(size * sizeof(char));

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
