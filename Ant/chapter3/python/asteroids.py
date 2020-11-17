def ns(f):
    return next(f).strip()


with open("../testset/asteroids/test1.txt", 'r') as f:
    N, K = map(int, ns(f).split())
    G = [[] for _ in range(N * 2)]
    for _ in range(K):
        x, y = map(int, ns(f).split())
        x -= 1
        y -= 1
        G[x].append(N + y)
        G[N + y].append(x)

match = [-1] * (N * 2)


def dfs(u, used):
    global match
    used[u] = True
    for v in G[u]:
        _u = match[v]
        if _u < 0 or (not used[_u] and dfs(_u, used)):
            match[u] = v
            match[v] = u
            return True
    return False


def bipartite_matching():
    res = 0
    for u in range(N):
        if match[u] < 0:
            used = [False] * (N * 2)
            if dfs(u, used):
                res += 1
    return res


res = bipartite_matching()
print(res)
