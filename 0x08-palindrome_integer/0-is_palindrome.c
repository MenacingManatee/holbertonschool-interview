#include "palindrome.h"


double _pow(double n, double x);
int find_digits(unsigned long x);
/**
 * is_palindrome - checks if an int is a palindrome
 * @n: Int to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int digits = find_digits(n);
	int i, j;

	for (i = 0, j = digits; i < j; i++, j--)
	{
		if (!((n / (int)_pow(10, i)) % 10 == (n / (int)_pow(10, j - 1)) % 10))
			return (0);
	}
	return (1);
}
/**
 * _pow - raises a number n to the power x
 * @n: number to raise
 * @x: power to raise it to
 *
 * Return: final number
 */
double _pow(double n, double x)
{
	int i = 0;
	long sum = 1;

	for (; i < x; i++)
		sum = sum * n;
	return (sum);
}
/**
 * find_digits - finds the number of digits of a number
 * @x: Number to find the digits of
 *
 * Return: Number of digits
 */
int find_digits(unsigned long x)
{
	int count = 0;

	while (x > 0)
	{
		count++;
		x /= 10;
	}
	return count;
}
