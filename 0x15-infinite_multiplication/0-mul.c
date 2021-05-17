#include <stdlib.h>
#include "holberton.h"

/**
 * print_string
 * @s: string to print
 *
 * Return: 0 on success, 1 otherwise
 */
int print_string(char *s)
{
	int i;

	if (!s)
		return (1);
	for (i = 0; s[i]; i++)
		_putchar(s[i]);
	return (0);
}
/**
 * _strlen - checks the length of a string
 * @s: string to check
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}

/**
 * check_int - checks if a string can be represented as a number
 * @s: string to check
 *
 * Return: 0 on failure, 1 on success
 */
int check_int(char *s)
{
	int i = 0;
	int len = _strlen(s);
	int flag = 1;

	for (; i < len; i++)
	{
		if (!(s[i] >= 48 && s[i] <= 57))
			flag = 0;
	}
	return (flag);
}

/**
 * main - multiplies 2 numbers of theoretically infinite size
 *
 * Return: Always 0 (ok)
 */
int main(int argc, char **argv)
{
	if (argc != 3 || (!check_int(argv[1]) || !check_int(argv[2])))
	{
		print_string("Error\n");
		return (98);
	}
	return (0);
}
