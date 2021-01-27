#!/usr/bin/python3
'''Log parsing tool'''


import sys


def stats(inp, count, size, dic={}):
    '''Parses logs sent to file'''
    data = inp.split()
    size += int(data[8])
    if dic.get(data[7]) is None:
        dic.update({data[7]: 1})
    else:
        dic.update({data[7]: dic.get(data[7]) + 1})
    if count % 10 == 9:
        printData(size, dic)
    return size, dic


def printData(size, data):
    '''Prints the parsed data'''
    print("File size: {:d}".format(size))
    tmp = list(data.keys())
    tmp.sort()
    for item in tmp:
        print("{}: {}".format(item, data.get(item)))


count = 0
size = 0
data = {}
try:
    for line in sys.stdin:
        size, data = stats(line, count, size, data)
        count += 1
    sys.stdout.flush()
finally:
    printData(size, data)
    sys.stdout.flush()
exit(0)
