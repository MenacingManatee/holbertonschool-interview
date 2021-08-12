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
 * regex_strcmp - compares two strings using . and *
 *@s1: string 1 to be compared
 *@s2: string 2 to be compared
 * Return: a positive, negative, or 0 number based on the first different char
 */
int regex_strcmp(const char *s1, const char *s2)
{
	int i = 0, j = 0;

	while (s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] == s2[j])
			i++, j++;
		else if (s2[j] == '.')
		{
			if (s2[j + 1] == '*')
			{
				if (s1[i + 1] == (s2[j + 2])) /*End * */
					i++, j += 2;
				else if (s1[i] == s2[j + 2])/*Skip * */
					j += 2;
				else
					i++, j++; }
			else
				i++, j++; }
		else if (s2[j] == '*')
		{
			if (s2[j + 1] == '\0' && s2[j - 1] == '.')
				return (0); /*0 for matching, easy exit condition*/
			if (s2[j + 1] == s1[i] || s2[j + 1] == s1[i + 1])
				i++, j++;
			else if (s1[i] == s2[j - 1])
				i++;
			else
				break; }
		else
		{
			if (s2[j + 1] == '*')
				j += 2;
			else
				break; }
	}
	if (s1[i] == s2[j])
		return (0);
	else
		return (s1[i] - s2[j]);
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
	if (_strcmp(pattern, "") == 0 && _strcmp(str, "") != 0)
		return (0);
	if (_strcmp(pattern, ".*") == 0)
		return (1);
	return (regex_strcmp(str, pattern) == 0 ? 1 : 0);
}
