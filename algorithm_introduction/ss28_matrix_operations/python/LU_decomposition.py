from typing import List
from pprint import pprint


def LU_decomposition(A: List[List[int]]):
    N = len(A)
    for i in range(N - 1):
        for j in range(i + 1, N):
            A[j][i] //= A[i][i]
        for j in range(i + 1, N):
            for k in range(i + 1, N):
                A[j][k] -= A[j][i] * A[i][k]


A = [
    [2, 3, 1, 5],
    [6, 13, 5, 19],
    [2, 19, 10, 23],
    [4, 10, 11, 31]
]

LU_decomposition(A)

pprint(A)
