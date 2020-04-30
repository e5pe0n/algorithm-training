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

for i in range(1, 5):
    r = [0] * 40
    start = time.perf_counter_ns()
    res = memoized_cut_rod_aux(p, 2**i, r)
    end = time.perf_counter_ns()
    duration = end - start
    print(f'n: {i}, res: {res}, duration: {duration}[ns]')

"""
n: 1, res: 5, duration: 6666[ns]
n: 2, res: 10, duration: 9914[ns]
n: 3, res: 22, duration: 24518[ns]
n: 4, res: 47, duration: 82062[ns]
"""
