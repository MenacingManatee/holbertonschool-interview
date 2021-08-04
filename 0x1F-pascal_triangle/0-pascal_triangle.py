#!/usr/bin/python3
'''
Returns a list of lists of integers representing of a pascal triangle
'''


def pascal_triangle(n):
    '''Usage: pascal_triangle(size)'''
    res = []
    l = []
    if n <= 0:
        return res
    for i in range(0, n):
        if i == 0:
            res.append([1])
            continue
        else:
            for j in range(0, i + 1):
                num = 0
                if j < i:
                    num += res[i - 1][j]
                if j > 0:
                    num += res[i - 1][j - 1]
                l.append(num)
            res.append(l.copy())
            l.clear()
    return res
