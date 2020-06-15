from typing import List, Tuple
from pprint import pprint


INF = 1_000_000_000
S = 6
R = 4
C = 4

L = [0] * C
E = [0] * R
N = [0] * C
B = [0] * R


def pivot(A: List[List[float]], v: float, l: int, e: int) -> float:
    global L, E, N, B

    a = 1 / A[l][e]
    for i in range(R):
        E[i] = A[i][e]
    for j in range(C):
        L[j] = -A[l][j] * a
    L[e] = a

    v += -A[l][C - 1] * a * A[R - 1][e]

    for i in range(R):
        for j in range(C):
            A[i][j] += L[j] * E[j]
        A[i][e] = E[i] * a
    for j in range(C):
        A[l][j] = L[j]

    B[l], N[e] = N[e], B[l]
    return v


def initialize_simplex():
    global B, N

    for j in range(C - 1):
        N[j] = j
    for i in range(R - 1):
        B[i] = C - 1 + i


def simplex(A: List[List[float]]) -> Tuple[float, List[float]]:
    X = [0] * S
    e = -1
    l = -1
    v = A[R - 1][C - 1]
    while True:
        positive_c_idx_list = []
        for j in range(C - 1):
            if A[R - 1] > 0:
                positive_c_idx_list.append(j)

        if len(positive_c_idx_list) == 0:
            break

        max_f_dlt = 0
        for j in range(len(positive_c_idx_list)):
            min_x_dlt = INF
            min_x_idx = -1
            for i in range(R - 1):
                if A[i][positive_c_idx_list[j]] < 0:
                    x_dlt = -A[i][C - 1] / A[i][positive_c_idx_list[j]]
                    if x_dlt < min_x_dlt:
                        min_x_dlt = x_dlt
                        min_x_idx = i

            if min_x_dlt > 0:
                f_dlt = A[R - 1][positive_c_idx_list[j]] * min_x_dlt
                if f_dlt > max_f_dlt:
                    max_f_dlt = f_dlt
                    l = min_x_idx
                    e = positive_c_idx_list[j]

        if e < 0:
            raise ValueError('Not finite')
        else:
            v = pivot(A, v, l, e)

    for k in range(C - 1):
        X[B[k]] = A[k][C - 1]
    # for k in range(R - 1):
    #     X[N[k]] = 0
    return v, X


A = [
    [-1, -1, -3, 30],
    [-2, -2, -5, 24],
    [-4, -1, -2, 36],
    [3, 1, 2, 0]
]

try:
    res, X = simplex(A)
    print('res: %.3f' % res)
    print('X:', X)
    pprint(A)
except ValueError as err:
    print(err)
