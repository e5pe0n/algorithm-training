from typing import List


N = 6
p = [-1] * N
d = [0] * N
f = [0] * N
time = 0


def dfs(V: List[List[int]], N: int, p: int, d: int, f: int):
    global time

    time = 0
    for u in range(N):
        if d[u] <= 0:
            dfs_visit(V, u, p, d, f)


def dfs_visit(V: List[List[int]], u: int, p: int, d: int, f: int):
    global time

    time += 1
    d[u] = time
    for v in V[u]:
        if d[v] <= 0:
            p[v] = u
            dfs_visit(V, v, p, d, f)
    time += 1
    f[u] = time


V = [
    [1, 3],
    [4],
    [4, 5],
    [1],
    [3],
    [5]
]

dfs(V, N, p, d, f)
