#!/usr/bin/python3


import sys


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
