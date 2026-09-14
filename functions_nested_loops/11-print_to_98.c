#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @n: The integer to print
 */
static void print_unsigned(unsigned int n)
{
	if (n / 10 != 0)
		print_unsigned(n / 10);

	_putchar((n % 10) + '0');
}

/**
 * print_number - Prints a signed integer
 * @n: The integer to print
 */
static void print_number(int n)
{
	unsigned int number;

	if (n < 0)
	{
		_putchar('-');
		number = -(unsigned int)n;
	}
	else
	{
		number = (unsigned int)n;
	}

	print_unsigned(number);
}

/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: The number at which to start
 */
void print_to_98(int n)
{
	while (1)
	{
		print_number(n);

		if (n == 98)
			break;

		_putchar(',');
		_putchar(' ');

		if (n < 98)
			n++;
		else
			n--;
	}

	_putchar('\n');
}