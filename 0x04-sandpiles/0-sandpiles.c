#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * sandify - Balances a sandpile
 *
 * @grid: Grid to balance
 * Return: Void
 */
void sandify(int grid[3][3])
{
    int i, topple;
    int ord_i[9] = {1, 0, 2, 1, 1, 0, 0, 2, 2};
    int ord_j[9] = {1, 1, 1, 0, 2, 0, 2, 0, 2};

    for (i = 0, topple = 0; i < 9; i++)
    {
	    if (grid[ord_i[i]][ord_j[i]] > 3)
	    {
		    if (topple == 0)
		    {
			    printf("=\n");
			    print_grid(grid);
		    }
		    topple = 1;
		    grid[ord_i[i]][ord_j[i]] -= 4;
		    if (ord_i[i] != 0)
			    grid[ord_i[i] - 1][ord_j[i]] += 1;
		    if (ord_i[i] != 2)
			    grid[ord_i[i] + 1][ord_j[i]] += 1;
		    if (ord_j[i] != 0)
			    grid[ord_i[i]][ord_j[i] - 1] += 1;
		    if (ord_j[i] != 2)
			    grid[ord_i[i]][ord_j[i] + 1] += 1;
            }
    }
    if (topple == 1)
	    sandify(grid);
}
/**
 * sandpiles_sum - Adds 2 sandpiles
 *
 * @grid1: First grid to add
 * @grid2: Second grid to add
 * Return: Void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i = 0, j = 0;

    if (grid1 == NULL || grid2 == NULL)
        return;

    for (; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }
    sandify(grid1);
}
