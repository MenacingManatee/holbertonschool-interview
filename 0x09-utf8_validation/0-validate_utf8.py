#!/usr/bin/python3
"""
Module for validating utf-8 encoding
"""


def validUTF8(data):
    '''Return: True if data is a valid UTF-8 encoding, else return False'''
    binary = []
    flag = 0
    count = 0
    for item in data:
        binary.append(int_to_binary(item))
    for item in binary:
        if count <= 0:
            flag = 0
            count = 0
        if flag == 0:
            for char in item:
                if char == '1':
                    count += 1
                else:
                    break
            count -= 1
            if count > 0:
                if count > 3:
                    return False
                flag = 1
        else:
            if item[:2] == "10":
                count -= 1
                continue
            else:
                return False
    return True


def int_to_binary(data):
    '''
    Converts an int less than 256 to a string representation of its binary
    '''
    bina = []
    for i in range(0, 8):
        bina.append(str(data % 2))
        data = data // 2
    bina.reverse()
    return "".join(bina)
