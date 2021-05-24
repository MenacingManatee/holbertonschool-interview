#!/usr/bin/python3
''' Matrix shenanigans '''


def rotate_2d_matrix(matrix):
    ''' Rotates a 2d matrix '''
    swapped = []
    count = len(matrix[0]) - 1
    for i in range(len(matrix)):
        tmp = []
        for j in range(len(matrix[0])):
            tmp.append(0)
        swapped.append(tmp.copy())
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            swapped[j][count] = matrix[i][j]
        count -= 1
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            matrix[i][j] = swapped[i][j]
