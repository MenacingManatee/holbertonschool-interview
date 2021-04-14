#!/usr/bin/python3

'''
Usage: rain(walls)
Walls is a list of non-negative integers
'''


def rain(walls):
    ''' Return: (int) Total amount of rainwater retained'''
    if len(walls) <= 2:
        return (0)
    saved = 0
    i = 0
    while i < len(walls) - 1:
        tmp = run(walls, i)
        if (tmp[1] > 0):
            saved += tmp[1]
        i = tmp[0]
    return (saved)


def run(walls, index):
    ''' Runs ahead to calculate reserved water '''
    m_num = -1
    m_i = -1
    for i in range(index + 1, len(walls)):
        if (walls[i] > m_num):
            m_num = walls[i]
            m_i = i
        if (walls[i] >= walls[index]):
            return (m_i, basin_size(walls, index, m_i))
    if (index + 1 == len(walls)):
        return (index, 0)
    else:
        return (index + 1, min(walls[index - 1],
                               walls[index + 1]) - walls[index])


def basin_size(walls, i1, i2):
    ''' Calculates the size of a large basin '''
    saved = 0
    size = min(walls[i1], walls[i2])
    for i in range(i1, i2):
        saved += size - walls[i]
    return saved
