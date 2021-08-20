#include "substring.h"
#include <stdlib.h>

int _strncmp(const char *s1, const char *s2, int n);
int _strlen(const char *s);
int check_match(const char *s, const char **words, int nb_words);
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
	int i;

	*n = 0; /*I can start undefined, this initializes to 0*/

	if (!s || !words || !*words || nb_words == 0)
		return (NULL); /*Edge case check*/
	res = malloc(sizeof(int) * _strlen(s)); /*max size possible*/
	if (!res)
		return (NULL);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (check_match(s + i, words, nb_words))
			res[(*n)++] = i;
	}
	if (*n == 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
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
/**
 * check_match - Checks for a full match
 * @s: String to check
 * @words: Array of words to check against s
 * @nb_words: Size of words array
 *
 * Return: 1 on pass, 0 on fail
 */
int check_match(const char *s, const char **words, int nb_words)
{
	int *skip;
	int i, j, match = 1, flag = 0;

	skip = malloc(sizeof(int) * nb_words);
	for (i = 0; i < nb_words; i++)
		skip[i] = 0;
	for (i = 0; i < nb_words; i++)
	{
		for (j = 0; j < nb_words; j++)
		{
			flag = 0;
			if (skip[j])
				continue;
			if (!_strncmp(s + i, words[j], _strlen(words[j])))
			{
				skip[j] = 1;
				i += _strlen(words[j]) - 1;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			match = 0;
			break;
		}
	}
	return (match);
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
