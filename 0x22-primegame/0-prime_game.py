#!/usr/bin/python3
'''Runs the checker for prime game'''


def isWinner(x, nums):
    '''
    Usage: isWinner(rounds, numarray)
    Return: name of the player that won the most rounds
    '''
    count = 0
    if x <= 0 or nums == None or nums == []:
        return None
    for num in nums.copy():
        if x <= 0:
            return "Ben" if count % 2 == 0 else "Maria"
        elif num not in nums:
            continue
        if isPrime(num):
            nums.remove(num)
            for i in nums:
                if num % i == 0 and num != i:
                    nums.remove(i)
        count += 1
    if count == 0:
        return 0
    return "Ben" if count % 2 == 0 else "Maria"


def isPrime(num):
    ''' Checks if a number is prime '''
    if num < 2:
        return 0
    if num % 2 == 0:
        return 0 if num is not 2 else 1
    for i in range(3, num // 2, 2):
        if i ** 2 > num:
            return 1
        if num % i == 0:
            return 0
    return 1
