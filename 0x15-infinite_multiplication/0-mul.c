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
 * mul - multiplies 2 numbers represented as strings
 *
 * @num1: number 1
 * @num2: number 2
 *
 * Return: multiplied number or NULL on failure
 */
char *mul(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int i;
	char *res = malloc(sizeof(char) * (len1 + len2)); /*max length*/

	if (res == NULL)
		return (NULL);
	for (i = 0; i < (len1 + len2); i++)
		res[i] = '0';
	return (res);
}

/**
 * main - multiplies 2 numbers of theoretically infinite size
 *
 * Return: Always 0 (ok)
 */
int main(int argc, char **argv)
{
	char *res;

	if (argc != 3 || (!check_int(argv[1]) || !check_int(argv[2])))
	{
		print_string("Error\n");
		return (98);
	}
	res = mul(argv[1], argv[2]);
	if (res == NULL)
	{
		print_string("Error\n");
		return (98);
	}
	print_string(res);
	_putchar('\n');
	free(res);
	return (0);
}
