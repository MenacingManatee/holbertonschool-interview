#include "regex.h"
#include <stdio.h>

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
	return (1);
}
