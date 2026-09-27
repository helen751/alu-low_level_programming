#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: String whose length is measured
 *
 * Return: The number of characters in s
 */
int _strlen(char *s)
{
	int length;

	length = 0;
	while (s[length] != '\0')
		length++;

	return (length);
}
