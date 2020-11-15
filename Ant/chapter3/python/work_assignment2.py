def ns(f):
    return next(f).strip()


with open("../testset/work_assignment/test2.txt", 'r') as f:
    N, M, K = map(int, ns(f).split())
    V = N + M
    G = [[] for _ in range(V)]
    for _ in range(K):
        u, v = map(int, ns(f).split())
        u -= 1
        v -= 1
        G[u].append(v)
        G[v].append(u)


match = [-1] * V


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


res = 0
for u in range(N):
    if match[u] < 0:
        used = [False] * V
        if dfs(u, used):
            res += 1
print(res)
