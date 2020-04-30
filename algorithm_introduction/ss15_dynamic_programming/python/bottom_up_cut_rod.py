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

for j in (2**i for i in range(2, 6)):
    start = time.perf_counter_ns()
    res = bottom_up_cut_rod(p, j)
    end = time.perf_counter_ns()
    duration = end - start
    print(f'n: {j}, res: {res}, duration: {duration}[ns]')

"""
n: 4, res: 10, duration: 9938[ns]
n: 8, res: 22, duration: 20020[ns]
n: 16, res: 47, duration: 61082[ns]
n: 32, res: 95, duration: 224063[ns]
"""
