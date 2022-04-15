#!/usr/bin/python3
"""this module measures rainfall."""


def rain(walls):
    """finds the retained amount of water"""
    total = 0
    wall1 = -1
    wall2 = -1

    for i in range(len(walls)):
        if wall1 == -1 and walls[i] > 0:
            wall1 = i
        elif wall1 != -1 and walls[i] >= walls[wall1]:
            total += (i - (wall1 + 1)) * walls[wall1]
            wall1 = i

    for j in range(len(walls) - 1, -1, -1):
        if wall2 == -1 and walls[j] > 0:
            wall2 = j
        elif wall2 != -1 and walls[j] >= walls[wall2]:
            total += (wall2 - (j + 1)) * walls[wall2]
            wall2 = j
        if wall2 == wall1:
            break

    return total
