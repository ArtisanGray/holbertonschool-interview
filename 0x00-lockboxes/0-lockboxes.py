#!/usr/bin/python3
"""this module determines if boxes can be unlocked."""


def canUnlockAll(boxes):
    """this class determines of a set of boxes can be unlocked."""
    if boxes is None:
        return False
    isUnlocked = {}
    i = 0
    for x in range(len(boxes)):
        isUnlocked[str(x)] = "False"
    isUnlocked['0'] = "True"
    for j in range(2):
        i = 0
        for item in boxes:
            if isUnlocked[str(i)] == "True":
                for k in range(len(item)):
                    if item is None:
                        break
                    if item[k] <= len(boxes):
                        isUnlocked[str(item[k])] = "True"
            i += 1
    for key, value in isUnlocked.items():
        if value == "False":
            return False
        return True
