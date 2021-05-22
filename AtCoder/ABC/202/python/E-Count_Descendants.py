from bisect import bisect_left
from sys import setrecursionlimit
setrecursionlimit(10**9)

N = int(input())
P = list(map(int, input().split()))
G = [[] for _ in range(N)]
for i, p in enumerate(P, 1):
    G[p - 1].append(i)

ins = [0] * N
outs = [0] * N
mat = [[] for _ in range(N)]

cnt = 0


def dfs(u, d):
    global ins, outs, mat, cnt
    ins[u] = cnt
    mat[d].append(ins[u])
    cnt += 1
    for v in G[u]:
        dfs(v, d + 1)
    outs[u] = cnt
    cnt += 1


dfs(0, 0)

Q = int(input())
for _ in range(Q):
    U, D = map(int, input().split())
    U -= 1
    print(bisect_left(mat[D], outs[U]) - bisect_left(mat[D], ins[U]))
