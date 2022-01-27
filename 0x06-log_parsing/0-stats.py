#!/usr/bin/python3
"""this module parses an input log."""
import fileinput
from collections import Counter


def isValid(string):
    """returns whether or not a string should be skipped"""
    if string.count('\"') == 2 and string.count('[') == 1 and \
            string.count(']') == 1:
        return True
    return False


def printLine(size, codes):
    """prints the 10th line, if not skipped."""
    netcodes = Counter(codes).most_common()
    sorted = unique(codes)
    sorted.sort()
    netcodes = dict(netcodes)
    print("File size: {}".format(size))
    for x in range(0, len(sorted)):
        print("{}: {}".format(sorted[x], netcodes[sorted[x]]))


def unique(list1):
    """literally a simple geeksforgeeks implementation"""
    unique_list = []
    for x in list1:
        if x not in unique_list:
            unique_list.append(x)
    return unique_list


try:

    i = 0
    size = 0
    codes = []
    for line in fileinput.input():
        if isValid(line):
            split = line.split(" ")
            size += int(split[8])
            codes.append(split[7])
        if i == 10:
            if isValid(line):
                printLine(size, codes)
            i = 0
        i += 1
except KeyboardInterrupt:
    pass
finally:
    if isValid(line):
        split = line.split(" ")
        codes.append(split[7])
        printLine(size, codes)
