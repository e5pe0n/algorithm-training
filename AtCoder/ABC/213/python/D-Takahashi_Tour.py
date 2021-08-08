from sys import setrecursionlimit
setrecursionlimit(10**9)

N = int(input())
G = [[] for _ in range(N)]
for _ in range(N - 1):
    a, b = map(lambda x: int(x) - 1, input().split())
    G[a].append(b)
    G[b].append(a)

res = []
used = [False] * N


def dfs(u):
    global res, used
    res.append(u)
    for v in G[u]:
        if not used[v]:
            used[v] = True
            dfs(v)
            res.append(u)


G = list(map(sorted, G))
used[0] = True
dfs(0)
print(" ".join(map(lambda x: str(x + 1), res)))
