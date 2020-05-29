from pprint import pprint
from typing import List


def square_matrix_multiply_recursive(
    C: List[List[int]], ic: int, jc: int,
    A: List[List[int]], ia: int, ja: int,
    B: List[List[int]], ib: int, jb: int,
    N: int
):
    if N == 1:
        C[ic][jc] = A[ia][ja] * B[ib][jb]
    else:
        T = [[0] * N for _ in range(N)]

        ia00, ja00 = ia, ja
        ib00, jb00 = ib, jb
        ic00, jc00 = ic, jc
        it00, jt00 = 0, 0

        ia01, ja01 = ia, ja + N // 2
        ib01, jb01 = ib, jb + N // 2
        ic01, jc01 = ic, jc + N // 2
        it01, jt01 = 0, N // 2

        ia10, ja10 = ia + N // 2, ja
        ib10, jb10 = ib + N // 2, jb
        ic10, jc10 = ic + N // 2, jc
        it10, jt10 = N // 2, 0

        ia11, ja11 = ia + N // 2, ja + N // 2
        ib11, jb11 = ib + N // 2, jb + N // 2
        ic11, jc11 = ic + N // 2, jc + N // 2
        it11, jt11 = N // 2, N // 2

        square_matrix_multiply_recursive(C, ic00, jc00, A, ia00, ja00, B, ib00, jb00, N // 2)
        square_matrix_multiply_recursive(C, ic01, jc01, A, ia00, ja00, B, ib01, jb01, N // 2)
        square_matrix_multiply_recursive(C, ic10, jc10, A, ia10, ja10, B, ib00, jb00, N // 2)
        square_matrix_multiply_recursive(C, ic11, jc11, A, ia10, ja10, B, ib01, jb01, N // 2)
        square_matrix_multiply_recursive(T, it00, jt00, A, ia01, ja01, B, ib10, jb10, N // 2)
        square_matrix_multiply_recursive(T, it01, jt01, A, ia01, ja01, B, ib11, jb11, N // 2)
        square_matrix_multiply_recursive(T, it10, jt10, A, ia11, ja11, B, ib10, jb10, N // 2)
        square_matrix_multiply_recursive(T, it11, jt11, A, ia11, ja11, B, ib11, jb11, N // 2)

        for i in range(N):
            for j in range(N):
                C[ic + i][jc + j] += T[i][j]


N = 4
A = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
B = [[11, 12, 13, 14], [15, 16, 17, 18], [19, 20, 21, 22], [23, 24, 25, 26]]
C = [[0] * N for _ in range(N)]

square_matrix_multiply_recursive(C, 0, 0, A, 0, 0, B, 0, 0, N)

pprint(C)

# [[190, 200, 210, 220],
#  [462, 488, 514, 540],
#  [734, 776, 818, 860],
#  [1006, 1064, 1122, 1180]]
