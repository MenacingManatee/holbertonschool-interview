#include "substring.h"
#include <stdlib.h>

/**
 * find_substring - finds all the possible substrings
 * containing a list of words, within a given string.
 * @s: the string to scan
 * @words: the array of words
 * @nb_words: the number of elements in the array words
 * @n:the address at which to store the number of elements
 * Return: an allocated array, storing each index in s, or NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *res;

	if (s == NULL || words == NULL || *words == NULL)
		return (NULL);
	if (nb_words == 0)
	{
		n = 0;
		res = malloc(sizeof(int *) * 1);
		return (res);
	}
	return (NULL);
}
