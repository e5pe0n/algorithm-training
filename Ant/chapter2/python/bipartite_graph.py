def ns(f):
    return next(f).strip()


with open("../testset/bipartite_graph/test3.txt", 'r') as f:
    N, K = map(int, ns(f).split())
    G = [[] for _ in range(N)]
    for _ in range(K):
        u, v = map(int, ns(f).split())
        u -= 1
        v -= 1
        G[u].append(v)
        G[v].append(u)

color = [0] * N


def dfs(u, c):
    global color
    color[u] = c
    for v in G[u]:
        if color[v] == c:
            return False
        if color[v] == 0 and not dfs(v, -c):
            return False
    return True


if dfs(0, 1):
    print("Yes")
else:
    print("No")
