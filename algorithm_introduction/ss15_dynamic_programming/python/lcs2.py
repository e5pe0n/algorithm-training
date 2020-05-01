from typing import List


def lcs_length(X: str, Y: str) -> List[int]:
    c = [[0 for _ in range(len(Y) + 1)] for _ in range(len(X) + 1)]
    for i in range(1, len(X) + 1):
        for j in range(1, len(Y) + 1):
            if X[i - 1] == Y[j - 1]:
                c[i][j] = c[i - 1][j - 1] + 1
            elif c[i - 1][j] >= c[i][j - 1]:
                c[i][j] = c[i - 1][j]
            else:
                c[i][j] = c[i][j - 1]
    return c


def print_lcs(c: List[int], X: str, i: int, j: int):
    if i == 0 or j == 0:
        return
    elif c[i - 1][j] < c[i][j - 1]:
        print_lcs(c, X, i, j - 1)
    elif c[i - 1][j] == c[i][j]:
        print_lcs(c, X, i - 1, j)
    else:
        print_lcs(c, X, i - 1, j - 1)
        print(f'{X[i - 1]}, ', end='')


X = 'ABCBDAB'
Y = 'BDCABA'

c = lcs_length(X, Y)
print_lcs(c, X, len(X), len(Y))  # B, C, B, A,
print()
