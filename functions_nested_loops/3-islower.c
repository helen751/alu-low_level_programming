#include "main.h"

/**
 * _islower - Checks for a lowercase character
 * @c: The character to check
 *
 * Return: 1 if c is lowercase, otherwise 0
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
