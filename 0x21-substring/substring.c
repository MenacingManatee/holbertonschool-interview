#include "substring.h"
#include <stdlib.h>

int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, int n);
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
	int *res, i, j;

	*n = 0;
	if (s == NULL || words == NULL || *words == NULL)
		return (NULL);
	if (nb_words == 0)
	{
		(void)n;
		n = 0;
		res = malloc(sizeof(int *) * 1);
		return (res);
	}
	for (i = 0; s[i]; i++)
	{
		for (j = 0; j < nb_words; j++)
		{
			if (words[j][0] == s[i])
			{
				if (_strncmp(s + i, words[j], _strlen(words[j])) == 0)
				{
					(*n)++;
					res = malloc(sizeof(int *) * 1);
					res[0] = i;
					return (res);
				}
			}
		}
	}
	return (NULL);
}
/**
 * _strncmp - compares two strings
 *@s1: string 1 to be compared
 *@s2: string 2 to be compared
 * @n: max length to compare
 * Return: a positive, negative, or 0 number based on the first different char
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i = 0;

	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i] && i < n - 1)
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}
/**
 * _strlen - returns the length of a string
 * @s: a string (pointer to the first letter) provided by user
 * Return: string length
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
