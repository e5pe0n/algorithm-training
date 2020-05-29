from time import perf_counter
from concurrent.futures.process import ProcessPoolExecutor
from functools import partial
from typing import List


def calc(i: int, A: List[List[int]], x: List[int], y: List[int]):
    for j in range(len(A)):
        y[i] += A[i][j] * x[j]


def mat_vec(A: List[List[int]], x: List[int]) -> List[int]:
    N = len(A)
    y = [0] * N
    f = partial(calc, A=A, x=x, y=y)

    pool = ProcessPoolExecutor(max_workers=2)
    pool.map(f, [i for i in range(N)])
    pool.shutdown(wait=True)

    return y


n = [400, 800, 1600, 3200, 6400]
for N in n:
    A = [[1] * N for _ in range(N)]
    x = [1] * N
    start = perf_counter()
    mat_vec(A, x)
    end = perf_counter()
    duration = end - start
    print('N: %d, duration: %f' % (N, duration))

# N: 400, duration: 2.460950
# N: 800, duration: 18.634018
# N: 1600, duration: 151.982575
