#!/usr/bin/python3


def canUnlockAll(boxes):
    if boxes is None or len(boxes) <= 1:
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
    bx = boxes.copy()
    bx.pop(0)
    if len(keys) >= len(bx):
        return True
    return False
