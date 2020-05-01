import sys
from typing import List, Tuple

I_MAX = sys.maxsize


def matrix_chain_order(p: List[int]) -> List[int]:
    n = len(p) - 1
    m = [[I_MAX for _ in range(10)] for _ in range(10)]
    s = [[0 for _ in range(10)] for _ in range(10)]
    for i in range(10):
        m[i][i] = 0
    for l in range(2, n + 1):
        for i in range(1, n - l + 2):
            j = i + l - 1
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k
    return s


def print_optimal_parser(s: List[int], i: int, j: int):
    if i == j:
        print(f'A{i}', end='')
    else:
        print('(', end='')
        print_optimal_parser(s, i, s[i][j])
        print_optimal_parser(s, s[i][j] + 1, j)
        print(')', end='')


p = [30, 35, 15, 5, 10, 20, 25]
s = matrix_chain_order(p)
print_optimal_parser(s, 1, 6)   # ((A1(A2A3))((A4A5)A6))
print()
