#include "main.h"

/**
 * find_square_root - searches recursively for a natural square root
 * @n: number whose square root is required
 * @candidate: possible square root
 *
 * Return: natural square root of n, or -1 if none exists
 */
static int find_square_root(int n, int candidate)
{
	if (candidate > n / candidate)
		return (-1);
	if (candidate * candidate == n)
		return (candidate);

	return (find_square_root(n, candidate + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number whose square root is required
 *
 * Return: natural square root of n, or -1 if none exists
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);

	return (find_square_root(n, 1));
}
