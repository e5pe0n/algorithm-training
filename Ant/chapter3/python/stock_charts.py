def ns(f):
    return next(f).strip()


with open("../testset/stock_charts/test1.txt", 'r') as f:
    N, K = map(int, ns(f).split())
    P = [list(map(int, ns(f).split())) for _ in range(N)]

V = N * 2
G = [[] for _ in range(V)]


def add_edge(u, v):
    global G
    G[u].append(v)
    G[v].append(u)


def dfs(u, used, match):
    used[u] = True
    for v in G[u]:
        _u = match[v]
        if _u < 0 or (not used[_u] and dfs(_u, used, match)):
            match[v] = u
            match[u] = v
            return True
    return False


def bipartite_matching():
    res = 0
    match = [-1] * V
    for u in range(N):
        if match[u] < 0:
            used = [False] * V
            if dfs(u, used, match):
                res += 1
    return res


for i in range(N):
    for j in range(N):
        if i == j:
            continue
        f = True
        for k in range(K):
            if P[j][k] >= P[i][k]:
                f = False
                break
        if f:
            add_edge(i, N + j)
print(N - bipartite_matching())
