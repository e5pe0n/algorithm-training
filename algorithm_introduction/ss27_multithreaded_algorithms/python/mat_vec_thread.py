from threading import Thread
from time import perf_counter
from typing import List


def calc(A: List[List[int]], x: List[int], y: List[int], i: int):
    for j in range(len(A)):
        y[i] += A[i][j] * x[j]


def mat_vec(A: List[List[int]], x: List[int]) -> List[int]:
    N = len(A)
    y = [0] * N
    threads = []
    for i in range(N):
        thread = Thread(target=calc, args=(A, x, y, i))
        threads.append(thread)
        thread.start()
    for thread in threads:
        thread.join()


n = [400, 800, 1600, 3200, 6400]
for N in n:
    A = [[1] * N for _ in range(N)]
    x = [1] * N
    start = perf_counter()
    mat_vec(A, x)
    end = perf_counter()
    duration = end - start
    print('N: %d, duration: %f' % (N, duration))

# N: 400, duration: 0.062034
# N: 800, duration: 0.206270
# N: 1600, duration: 0.640842
# N: 3200, duration: 2.660599
# N: 6400, duration: 10.031398
