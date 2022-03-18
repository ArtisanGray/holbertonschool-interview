#!/usr/bin/python3
''' this module solves n queens problem '''
import sys


def pos(board, row, column):
    ''' checks current position '''

    for y in range(column):
        if board[y] is row or abs(board[y] - row) is abs(y - column):
            return False
    return True


def ver(board, column):
    ''' verifies placement '''

    x = len(board)
    if column is x:
        print(str([[y, board[y]] for y in range(x)]))
        return

    for row in range(x):
        if pos(board, row, column):
            board[column] = row
            ver(board, column + 1)

if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    if sys.argv[1].isdigit() is False:
        print("N must be a number")
        sys.exit(1)

    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [0 for column in range(int(sys.argv[1]))]
    ver(board, 0)
