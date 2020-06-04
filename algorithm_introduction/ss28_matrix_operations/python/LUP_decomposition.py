from typing import List


def LUP_decomposition(A: List[List[float]]) -> List[int]:
    N = len(A)
    P = [i for i in range(N)]
    for k in range(N - 1):
        p = 0
        _k = 0
        for i in range(k + 1, N):
            if abs(A[i][k]) > p:
                p = abs(A[i][k])
                _k = i

        P[k], P[_k] = P[_k], P[k]
        A[k], A[_k] = A[_k], A[k]

        for i in range(k + 1, N):
            A[i][k] /= A[k][k]
            for j in range(k + 1, N):
                A[i][j] -= A[i][k] * A[k][j]

    return P.copy()


A = [
    [2, 0, 2, 0.6],
    [3, 3, 4, -2],
    [5, 5, 4, 2],
    [-1, -2, 3.4, -1]
]

N = len(A)

P = LUP_decomposition(A)

print('P:', P)
print('A:')
print('[', end='')
for i in range(N):
    if i > 0:
        print(' ', end='')
    print('[', end='')
    for j in range(N):
        print('%f, ' % A[i][j], end='')
    print(']', end='')
    if i < N - 1:
        print()
print(']')
