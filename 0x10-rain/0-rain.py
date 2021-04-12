#!/usr/bin/python3

'''
Usage: rain(walls)
Walls is a list of non-negative integers
'''

def rain(walls):
    ''' Return: (int) Total amount of rainwater retained'''
    if len(walls) == 0:
        return (0)
    saved = 0
    i = 0
    while i < len(walls) - 1:
        tmp = run(walls, i)
        saved += tmp[0]
        i = tmp[1]
    return (saved)


def run(walls, index):
    ''' Runs ahead to help calculate reserved water '''
    for i in range(index + 1, len(walls)):
        if (walls[i] >= walls[index]):
            if (index == 0 and i == len(walls) - 1):
                return ((i - index) * walls[index], i)
            return ((i - index) - 1) * walls[index], i
    if (index + 1 == len(walls)):
        return (0, index)
    else:
        return (min(walls[index], walls[index + 1]), index + 1)
