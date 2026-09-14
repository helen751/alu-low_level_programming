#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: The number at which to start
 */
void print_to_98(int n)
{
	int direction;

	direction = (n <= 98) ? 1 : -1;
	while (n != 98)
	{
		printf("%d, ", n);
		n += direction;
	}
	printf("98\n");
}
