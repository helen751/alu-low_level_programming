#include "main.h"

/**
 * print_digits - Prints the digits of a signed integer
 * @n: The integer whose digits will be printed
 */
static void print_digits(int n)
{
	int digit;

	if (n / 10 != 0)
		print_digits(n / 10);

	digit = n % 10;
	if (digit < 0)
		digit = -digit;

	_putchar(digit + '0');
}

/**
 * print_number - Prints a signed integer
 * @n: The signed integer to print
 */
static void print_number(int n)
{
	if (n < 0)
		_putchar('-');

	print_digits(n);
}

/**
 * print_to_98 - Prints all integers from n to 98
 * @n: The number at which to start
 */
void print_to_98(int n)
{
	while (n != 98)
	{
		print_number(n);
		_putchar(',');
		_putchar(' ');

		if (n < 98)
			n++;
		else
			n--;
	}

	print_number(98);
	_putchar('\n');
}
