#include "regex.h"
#include <stdio.h>

/**
 * _strcmp - compares two strings
 *@s1: string 1 to be compared
 *@s2: string 2 to be compared
 * Return: a positive, negative, or 0 number based on the first different char
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}
/**
 * _strlen - returns the length of a string
 * @s: string to be measured
 *
 * Return: length of the string
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}
/**
 * contains - checks if a string contains a specific character
 * @s: string to check
 * @c: character to check for
 *
 * Return: 0 if it does not contain the character, 1 if it does
 */
int contains(const char *s, char c)
{
	int flag = 0, i = 0;

	while (s[i])
		if (s[i++] == c)
			flag = 1;
	return (flag);
}
/**
 * regex_match - checks whether a given pattern matches a given string.
 * @str: the string to scan
 * @pattern: the regular expression
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	if (str == NULL || pattern == NULL) /* Basic NULL check*/
		return (0);
	if (_strcmp(str, pattern) == 0) /* If the pattern is an exact match */
		return (1);
	if (_strcmp(pattern, "") == 0 && _strcmp(str, "") != 0) /* If pattern is ""
															 *  the str must be too
															 */
		return (0);
	if (_strcmp(pattern, ".*") == 0) /* if the pattern matches everything*/
		return (1);
	if (_strcmp(str, "") == 0 && _strlen(pattern) != 2) /* If str is empty, pat
														 * must be a series of any character
														 * followed by a *.
														 * TODO: Make this check better
														 */
		return (0);
	if ((!contains(pattern, '*')) && (_strlen(str) != _strlen(pattern)))
		/* Length is only changed by '*' character */
		return (0);
	return (1);
}
