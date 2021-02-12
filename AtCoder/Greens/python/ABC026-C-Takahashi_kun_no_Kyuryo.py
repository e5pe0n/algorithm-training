INF = float('inf')
N = int(input())
G = [[]] + [[] for _ in range(N - 1)]
for i in range(N - 1):
    B = int(input())
    G[B - 1].append(i + 1)


def dfs(u):
    if len(G[u]) == 0:
        return 1
    mi = INF
    ma = 0
    for v in G[u]:
        x = dfs(v)
        mi = min(mi, x)
        ma = max(ma, x)
    if len(G[u]) == 1:
        return mi * 2 + 1
    return mi + ma + 1


print(dfs(0))
