#!/usr/bin/python3


import sys


def attackCheck(currSol):
    ''' '''
    if len(currSol) <= 1:
        return False

    res = False
    for item1 in currSol:
        for item2 in currSol:
            if item1 is item2:
                continue
            if (item2[1] == item1[1] or item2[0] == item1[0]):
                res = True
            elif (abs(item1[0] - item2[0]) == abs(item1[1] - item2[1])):
                res = True
    return res


def solver(currSol, n, col, start):
    if len(currSol) == 0:
        s = start
    else:
        s = 0
    '''if len(currSol) >= n:
        return True, currSol
    if col >= n:
        return True, currSol'''

    for i in range(s, n):
        if col == i:
            continue
        if attackCheck(currSol) is not True:
            currSol.append(list([col, i]))
            if len(currSol) > n:
                currSol.remove([col, i])
                return True, currSol
            if solver(currSol, n, col + 1, 0)[0] is True:
                return True, currSol
            else:
                currSol.remove([col, i])
    return False, currSol


'''Places n non-attacking queens on a nxn sized board'''
if len(sys.argv) <= 1:
    print("Usage: nqueens N")
    exit(1)
elif not sys.argv[1].isnumeric():
    print("N must be a number")
    exit(1)
elif int(sys.argv[1]) < 4:
    print("N must be at least 4")
    exit(1)
start = 0
solutions = []
solution = solver([], int(sys.argv[1]), 0, start)
while solution[0] is True and solution[1] != []:
    solutions.append(solution[1].copy())
    start = solution[1][0][1] + 1
    solution = solver([], int(sys.argv[1]), 0, start)
for item in solutions:
    if len(item) == int(sys.argv[1]):
        print(item)
