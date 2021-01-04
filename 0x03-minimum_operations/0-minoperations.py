#!/usr/bin/python3
'''
Given a number n, calculates the fewest
number of operations needed to result in exactly n H characters
'''


def minOperations(n):
    '''Determines the minimum operations, using only copy and paste'''
    l, buff = 1, 0
    count = 0
    if (l > n):
        return 0
    while (l < n):
        if (n % l == 0 and l > buff):
            buff = l  # Copy function
        else:
            l += buff  # Paste function
        count += 1
    return count
