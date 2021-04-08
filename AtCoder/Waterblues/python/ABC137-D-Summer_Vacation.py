from collections import defaultdict
from heapq import heapify, heappop, heappush
N, M = map(int, input().split())
C = defaultdict(list)
for _ in range(N):
    a, b = map(int, input().split())
    C[a].append(b)
q = []
heapify(q)
res = 0
for i in range(1, M + 1):
    for v in C[i]:
        heappush(q, -v)
    if len(q):
        res -= heappop(q)
print(res)
