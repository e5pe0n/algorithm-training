from typing import List
import sys
import time

INT_MIN = -sys.maxsize - 1


def cut_rod(p: List[int], n: int) -> int:
    if n == 0:
        return 0
    q = INT_MIN
    for i in range(n):
        q = max(q, p[i] + cut_rod(p, n - 1 - i))
    return q


n = 32
p = [0] * 40
q = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
for i in range(len(q)):
    p[i] = q[i]

start = time.perf_counter_ns()
res = cut_rod(p, n)
end = time.perf_counter_ns()
duration = end - start
print(f'n: {n}, res: {res}, duration: {duration}[ns]')

"""
n: 4, res: 10, duration: 15019[ns]
n: 8, res: 22, duration: 169146[ns]
n: 16, res: 47, duration: 44874848[ns]
n: 32, res: 95, duration: 2411756774675[ns]
"""
