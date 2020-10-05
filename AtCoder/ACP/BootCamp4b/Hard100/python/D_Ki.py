import sys
sys.setrecursionlimit(10**9)


N, Q = [int(x) for x in input().split()]
V = [[] for _ in range(N + 1)]
C = [0] * (N + 1)


def dfs(u, p):
    global C
    C[u] += C[p]
    for v in V[u]:
        if v != p:
            dfs(v, u)


for _ in range(N - 1):
    a, b = [int(x) for x in input().split()]
    V[a].append(b)
    V[b].append(a)
for _ in range(Q):
    P, X = [int(x) for x in input().split()]
    C[P] += X


p = 0
u = 1
dfs(u, p)
for c in C[1:]:
    print(c)
