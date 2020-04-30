import time
from typing import List


def memoized_cut_rod_aux(p: List, n: int, r: List) -> int:
    if n == 0:
        return 0
    if r[n] > 0:
        return r[n]
    for i in range(n):
        r[n] = max(r[n], p[i] + memoized_cut_rod_aux(p, n - i - 1, r))
    return r[n]


p = [0] * 40
q = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
for i in range(len(q)):
    p[i] = q[i]

for j in (2**i for i in range(2, 6)):
    r = [0] * 40
    start = time.perf_counter_ns()
    res = memoized_cut_rod_aux(p, j, r)
    end = time.perf_counter_ns()
    duration = end - start
    print(f'n: {j}, res: {res}, duration: {duration}[ns]')

"""
n: 4, res: 10, duration: 11393[ns]
n: 8, res: 22, duration: 25069[ns]
n: 16, res: 47, duration: 81558[ns]
n: 32, res: 95, duration: 307030[ns]
"""
