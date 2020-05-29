from time import perf_counter
from typing import List


def mat_vec(A: List[List[int]], x: List[int]) -> List[int]:
    N = len(A)
    y = [0] * N
    for i in range(N):
        for j in range(N):
            y[i] += A[i][j] * x[j]
    return y


n = [400, 800, 1600, 3200, 6400]
for N in n:
    A = [[1] * N for _ in range(N)]
    x = [1] * N
    start = perf_counter()
    mat_vec(A, x)
    end = perf_counter()
    duration = end - start
    print(f'N: %d, duration: %f' % (N, duration))

# N: 400, duration: 0.030869
# N: 800, duration: 0.136490
# N: 1600, duration: 0.590423
# N: 3200, duration: 2.430314
# N: 6400, duration: 9.452244
