#!/usr/bin/python3


def canUnlockAll(boxes):
    if boxes is None or type(boxes) is not list:
        return False
    if len(boxes) <= 1:
        return True
    keys = boxes[0].copy()
    i = 0
    i2 = 1  # instantiating them with a value to ignore first loop
    while len(keys) <= len(boxes) - 1 and i < i2:
        i = len(keys)
        keys2 = keys.copy()
        for item in keys2:
            keys.extend(boxes[item])
        keys = list(set(keys))
        i2 = len(keys)
    tmp = True
    for i in range(len(boxes)):
        if (i != 0 and i not in keys):
            tmp = False
    return tmp
