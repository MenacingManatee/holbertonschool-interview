#!/usr/bin/python3
'''Log parsing tool'''


import sys


def stats(inp, count, size, dic={}):
    '''Parses logs sent to file'''
    data = inp.split()
    size += int(data[8])
    if dic.get(data[7]) is None:
        return size, dic
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
        if data.get(item) != 0:
            print("{}: {}".format(item, data.get(item)))


count = 0
size = 0
data = {
    "200": 0, "301": 0, "400": 0,
    "401": 0, "403": 0, "404": 0,
    "405": 0, "500": 0
}
e = True
try:
    for line in sys.stdin:
        size, data = stats(line, count, size, data)
        count += 1
    e = False
    sys.stdout.flush()
finally:
    printData(size, data)
exit(0)
