#include "menger.h"
#include <math.h>
#include <stdlib.h>

char *conv_base_3(int num);
/**
 * menger - draw a 2D version of the Menger sponge
 * @level: the level of the Menger Sponge to draw
 *
 * Return: Void
 */
void menger(int level)
{
	int i, j, cols = pow(3, level - 1), flag = 0, i2;
	char *i3, *j3;

	if (level == 0)
		printf("#\n");
	for (i = 0; i < cols * 3; i++)
	{
		for (j = 0; j < cols * 3; j++)
		{
			i3 = conv_base_3(i);
			j3 = conv_base_3(j);
			for (i2 = 0; i2 < 9; i2++)
			{
				if (i3[i2] == j3[i2] && i3[i2] == '1')
				{
					flag = 1;
					break;
				}
			}
			free(i3);
			free(j3);
			if (flag == 1)
			{
				flag = 0;
				putchar(' ');
			}
			else
				putchar('#');
		}
		putchar('\n');
	}
}
/**
 * conv_base_3 - converts a base 10 int to base 3
 * @num: Base 10 number to convert
 *
 * Return: String representation of converted number up to 9 digits pending fix
 */
char *conv_base_3(int num)
{
	char *res;
	int i = 0;

	res = malloc(sizeof(char) * 9);
	for (i = 0; i < 9; i++)
		res[i] = '0';
	i = 0;
	while (num > 0)
	{
		res[i] = (num % 3) + 48;
		num /= 3;
		i++;
	}
	return (res);
}
