#include <math.h>
#include "palindrome.h"


/**
 * is_palindrome - checks if an int is a palindrome
 * @n: Int to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int digits = (int)ceil(log10(n));
	int i, j;

	for (i = 0, j = digits; i < j; i++, j--)
	{
		if (!((n / (int)pow(10, i)) % 10 == (n / (int)pow(10, j - 1)) % 10))
			return (0);
	}
	return (1);
}
