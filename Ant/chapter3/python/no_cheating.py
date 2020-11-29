def ns(f):
    return next(f).strip()


with open("../testset/no_cheating/test1.txt", 'r') as f:
    M, N = map(int, ns(f).split())
    seat = [list(ns(f)) for _ in range(M)]

dx = [-1, -1, 1, 1]
dy = [-1, 1, -1, 1]
V = M * N
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
            match[u] = v
            match[v] = u
            return True
    return False


def bipartite_matching():
    res = 0
    match = [-1] * V
    for x in range(0, N, 2):
        for y in range(M):
            u = x * M + y
            if match[u] < 0:
                used = [False] * V
                if dfs(u, used, match):
                    res += 1
    return res


num = 0
for y in range(M):
    for x in range(N):
        if seat[y][x] == '.':
            num += 1
            for _dx, _dy in zip(dx, dy):
                x2 = x + _dx
                y2 = y + _dy
                if 0 <= x2 < N and 0 <= y2 < M and seat[y2][x2] == '.':
                    add_edge(x * M + y, x2 * M + y2)
print(num - bipartite_matching())
