#!/usr/bin/python3
'''Runs the checker for prime game'''


def isWinner(x, nums):
    '''
    Usage: isWinner(rounds, numarray)
    Return: name of the player that won the most rounds
    '''
    if x <= 0 or nums == None or nums == []:
        return None
    ben, maria = 0, 0
    for num in nums:
        count = 0
        rnd = [i for i in range(1, num + 1)]
        for i in rnd.copy():
            if i not in rnd:
                continue
            if isPrime(i):
                rnd.remove(i)
                for j in rnd:
                    if j > 1 and j % i == 0 and i != j:
                        rnd.remove(j)
            count += 1
        if count % 2 == 1:
            ben += 1
        else:
            maria += 1
    if maria > ben:
        return "Maria"
    elif ben > maria:
        return "Ben"
    else:
        return None


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
