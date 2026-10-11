#include "main.h"

/**
 * check_prime - recursively checks whether a number has a divisor
 * @n: number to check
 * @divisor: possible divisor
 *
 * Return: 1 if n is prime, otherwise 0
 */
int check_prime(int n, int divisor)
{
	if (divisor > n / divisor)
		return (1);

	if (n % divisor == 0)
		return (0);

	return (check_prime(n, divisor + 1));
}

/**
 * is_prime_number - checks whether an integer is a prime number
 * @n: number to check
 *
 * Return: 1 if n is prime, otherwise 0
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);

	return (check_prime(n, 2));
}
