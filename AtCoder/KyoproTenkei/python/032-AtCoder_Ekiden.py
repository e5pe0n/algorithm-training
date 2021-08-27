# Wah!
# Python 3.8.2: TLE; 5513 ms
# PyPy 3: AC; 780 ms
from sys import setrecursionlimit
setrecursionlimit(10**9)
INF = float("inf")
N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]
M = int(input())
R = [[False] * N for _ in range(N)]
for _ in range(M):
    x, y = map(lambda x: int(x) - 1, input().split())
    R[x][y] = R[y][x] = True
used = [False] * N


def dfs(u, k, t):
    global used
    if k == N:
        return t
    res = INF
    for v in range(N):
        if not used[v] and not R[u][v]:
            used[v] = True
            res = min(res, dfs(v, k + 1, t + A[v][k]))
            used[v] = False
    return res


res = INF
for u in range(N):
    used[u] = True
    res = min(res, dfs(u, 1, A[u][0]))
    used[u] = False
print(res if res != INF else -1)
