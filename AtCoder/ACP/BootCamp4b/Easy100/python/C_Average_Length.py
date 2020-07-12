import math
from itertools import permutations
N = int(input())
C = [list(map(int, input().split())) for _ in range(N)]
perm = list(permutations(range(N)))
d = 0
for p in perm:
    for i in range(N - 1):
        d += math.sqrt((C[p[i]][0] - C[p[i + 1]][0]) ** 2 + (C[p[i]][1] - C[p[i + 1]][1]) ** 2)
print(d / len(perm))
