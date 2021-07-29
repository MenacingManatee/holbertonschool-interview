#include "holberton.h"
#include <stdio.h>

int skip(char *s);
int _strlen(char *s);
int checker(char *s1, char *s2);
/**
 * wildcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if not the same, 1 if the same
 */
int wildcmp(char *s1, char *s2)
{
	int x, len;

	len = _strlen(s1);
	x = checker(s1, s2);
	return (x == len);
}
/**
 * checker - checks if two strings are identical
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 or 1 if is not or is identical respectively
 */
int checker(char *s1, char *s2)
{
	int j = 0;

	if (*s1 == *s2 && *s1)
	{
		return (1 + checker(s1 + 1, s2 + 1));
	}
	else if (*s1 != '\0' && *s2 == '*')
	{

		if (*(s2 + 1) == '*')
		{
			j = skip(s2);
		}
		if (*(s1 + 1) == *(s2 + 1 + j))
		{
			return (1 + checker(s1 + 1, s2 + 1));
		}
		else if (*s1 == *(s2 + 1 + j))
		{
			if ((checker(s1 + 1, s2 + j)) > 3)
			{
				return (1 + checker(s1 + 1, s2 + j));
			}
			else
			{
				return (1 + checker(s1 + 1, s2 + 2 + j));
			}
		}
		else
		{
			return (1 + checker(s1 + 1, s2 + j));
		}
	}
	else if (*s1 == '\0' && *s2)
	{
		j = skip(s2);
		s2++;
		if (*(s2 + j) != '\0')
		{
			return (-2147483648);
		}
	}
	return (0);
}
/**
 * _strlen - gets the length of a function
 * @s: string to evaluate
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	if (*s)
		return (1 + _strlen(s + 1));
	return (0);
}
/**
 * skip - skips excessive wilds
 * @s: string to skip through
 * Return: the same string
 */
int skip(char *s)
{
	if (*s == '*' && *(s + 1) == '*')
	{
		s++;
		return (1 + skip(s));
	}
	return (0);
}
