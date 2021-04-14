#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print("{0} == {1}".format(rain(walls), 6))

    walls = []
    print("{0} == {1}".format(rain(walls), 0))


    walls = [3, 2, 1, 2, 3]
    print("{0} == {1}".format(rain(walls), 4))

    walls = [0, 1, 2, 3, 4, 5]
    print("{0} == {1}".format(rain(walls), 0))

    walls = [5, 1, 2, 5]
    print("{0} == {1}".format(rain(walls), 7))

    walls = [1, 0, 3, 1, 2, 0, 2, 0]
    print("{0} == {1}".format(rain(walls), 4))
