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

	*n = 0; /*I can start undefined, this initializes to 0*/

	if (!s || !words || !*words || nb_words == 0)
		return (NULL); /*Edge case check*/
	(void)n;
	res = malloc(sizeof(int) * 1);
	return (res);
}
