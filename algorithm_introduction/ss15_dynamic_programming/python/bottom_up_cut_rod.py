import time
from typing import List


def bottom_up_cut_rod(p: List, n: int) -> int:
    r = [0] * 40
    for j in range(1, n + 1):
        for i in range(1, j + 1):
            r[j] = max(r[j], p[i - 1] + r[j - i])
    return r[j]


p = [0] * 40
q = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
for i in range(len(q)):
    p[i] = q[i]

for i in range(1, 5):
    start = time.perf_counter_ns()
    res = bottom_up_cut_rod(p, 2**i)
    end = time.perf_counter_ns()
    duration = end - start
    print(f'n: {i}, res: {res}, duration: {duration}[ns]')

"""
n: 1, res: 5, duration: 7223[ns]
n: 2, res: 10, duration: 16622[ns]
n: 3, res: 22, duration: 20201[ns]
n: 4, res: 47, duration: 60926[ns]
"""
