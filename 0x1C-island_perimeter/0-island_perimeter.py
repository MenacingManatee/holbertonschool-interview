#!/usr/bin/python3
'''
Takes a matrix of ints and returns the perimeter
'''


def island_perimeter(grid):
    '''
    grid is a list of list of integers:
    0 represents water
    1 represents land
    '''
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                if i - 1 < 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                if i + 1 == len(grid) or grid[i + 1][j] == 0:
                    perimeter += 1
                if j - 1 < 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                if j + 1 == len(grid[0]) or grid[i][j + 1] == 0:
                    perimeter += 1
    return perimeter
