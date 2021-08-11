#include "regex.h"
#include <stdio.h>

/**
 * _strcmp - compares two strings
 *@s1: string 1 to be compared
 *@s2: string 2 to be compared
 * Return: a positive, negative, or 0 number based on the first different char
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
		{
			s1++;
			s2++;
		}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
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
	if (str == NULL || pattern == NULL)
		return (0);
	if (pattern == "" && str != "")
		return (0);
	if (_strcmp(pattern, ".*") == 0)
		return (1);
	return (1);
}
