#include "menger.h"
#include <math.h>

/**
 * menger - draw a 2D version of the Menger sponge
 * @level: the level of the Menger Sponge to draw
 *
 * Return: Void
 */
void menger(int level)
{
	int i, j, cols = pow(3, level - 1);
	int count = 1;

	if (level == 0)
		printf("#\n");
	for (i = 0; i < cols * 3; i++)
	{
		for (j = 0; j < cols * 3; j++)
		{
			if (i == 0)
				putchar('#');
			else if (i == 1)
			{
				if (count == (3 * j) - 2)
				{
					count++;
					putchar(' ');
				}
				else
					putchar('#');
			}
			else if (i == 2)
				putchar('#');
		}
		putchar('\n');
	}
}
