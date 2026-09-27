#include "main.h"

/**
 * puts_half - Prints the second half of a string
 * @str: String whose second half is printed
 */
void puts_half(char *str)
{
	int length;
	int index;

	length = 0;
	while (str[length] != '\0')
		length++;

	index = (length + 1) / 2;
	while (str[index] != '\0')
	{
		_putchar(str[index]);
		index++;
	}
	_putchar('\n');
}
