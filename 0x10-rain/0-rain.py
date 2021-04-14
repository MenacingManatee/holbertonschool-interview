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
    i = 1
    while i < len(walls) - 1:
        tmp = min(walls[i - 1], walls[i + 1])
        tmp -= walls[i]
        if (tmp > 0):
            saved += tmp
        i += 1
    return (saved)
