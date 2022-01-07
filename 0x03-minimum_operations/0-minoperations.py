#!/usr/bin/python3


def minOperations(n):
    """minimum required operations to reach x"""
    nOperations = 0
    length = 2
    if n < 2:
        return (0)
    while length < n + 1:
        while n % length == 0:
            nOperations += length
            n /= length
        length += 1
    return nOperations
