from itertools import combinations
import math
N, D = list(map(int, input().split()))
X = [list(map(int, input().split())) for _ in range(N)]
cnt = 0
for perm in list(combinations(range(N), 2)):
    d = sum(map(lambda x: (x[0] - x[1]) ** 2, zip(X[perm[0]], X[perm[1]])))
    if d == int(math.sqrt(d)) ** 2:
        cnt += 1
print(cnt)
