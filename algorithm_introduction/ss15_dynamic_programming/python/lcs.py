from enum import Enum
from typing import List


class Direction(Enum):
    UP = 0
    LEFT = 1
    UPLEFT = 2


def lcs_length(X: str, Y: str) -> List[Direction]:
    c = [[0 for _ in range(len(Y) + 1)] for _ in range(len(X) + 1)]
    b = [[Direction.UP for _ in range(len(Y) + 1)] for _ in range(len(X) + 1)]
    for i in range(1, len(X) + 1):
        for j in range(1, len(Y) + 1):
            if X[i - 1] == Y[j - 1]:
                c[i][j] = c[i - 1][j - 1] + 1
                b[i][j] = Direction.UPLEFT
            elif c[i - 1][j] >= c[i][j - 1]:
                c[i][j] = c[i - 1][j]
                b[i][j] = Direction.UP
            else:
                c[i][j] = c[i][j - 1]
                b[i][j] = Direction.LEFT
    return b


def print_lcs(b: List[Direction], X: str, i: int, j: int):
    if i == 0 or j == 0:
        return
    if b[i][j] == Direction.UPLEFT:
        print_lcs(b, X, i - 1, j - 1)
        print(f'{X[i - 1]}, ', end='')
    elif b[i][j] == Direction.UP:
        print_lcs(b, X, i - 1, j)
    else:
        print_lcs(b, X, i, j - 1)


X = 'ABCBDAB'
Y = 'BDCABA'

b = lcs_length(X, Y)
print_lcs(b, X, len(X), len(Y))  # B, C, B, A,
print()
