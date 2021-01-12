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
    int i, j, topple;

    for (i = 0, topple = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                topple = 1;
                grid[i][j] -= 4;
                if (i != 0)
                    grid[i - 1][j] += 1;
                if (i != 2)
                    grid[i + 1][j] += 1;
                if (j != 0)
                    grid[i][j - 1] += 1;
                if (j != 2)
                    grid[i][j + 1] += 1;
            }
        }
    }
    if (topple == 1)
    {
        printf("=\n");
        print_grid
    }
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