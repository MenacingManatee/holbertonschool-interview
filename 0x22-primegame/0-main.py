#!/usr/bin/python3

isWinner = __import__('0-prime_game').isWinner


print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3]))) # Expected: Ben
print("Winner: {}".format(isWinner(10, [5, 5, 5, 5, 5, 2, 2, 2, 2, 2]))) # Expected: Maria
print("Winner: {}".format(isWinner(0, [0]))) # Expected: None
print("Winner: {}".format(isWinner(-1, [10]))) # Expected: None
