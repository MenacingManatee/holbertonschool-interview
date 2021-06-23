#!/usr/bin/python3
'''determine the fewest number of coins needed to meet a given amount total'''


def makeChange(coins, total):
    '''
    Usage: makeChange(coins, total)
    Return: fewest number of coins needed to meet total
    '''
    if total <= 0:
        return 0
    count = 0
    coins.sort()
    coins.reverse()
    for coin in coins:
        if total / coin >= 1:
            count += total // coin
            total -= coin * (total // coin)
    if total == 0:
        return count
    return -1
