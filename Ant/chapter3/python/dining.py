INF = float('inf')


def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, v, cap, rev):
        self.v = v
        self.cap = cap
        self.rev = rev


with open("../testset/dining/test1.txt", 'r') as f:
    N, F, D = map(int, ns(f).split())
    likeF = [list(map(lambda x: int(x) - 1, ns(f).split()))[1:] for _ in range(N)]
    likeD = [list(map(lambda x: int(x) - 1, ns(f).split()))[1:] for _ in range(N)]

G = [[] for _ in range(N * 2 + F + D + 2)]


def add_edge(u, v, cap):
    global G
    G[u].append(Edge(v, cap, len(G[v])))
    G[v].append(Edge(u, 0, len(G[u]) - 1))


s = N * 2 + F + D
t = s + 1
for i in range(F):
    add_edge(s, N * 2 + i, 1)
for i in range(D):
    add_edge(N * 2 + F + i, t, 1)
for i in range(N):
    add_edge(i, N + i, 1)
    for f in likeF[i]:
        add_edge(N * 2 + f, i, 1)
    for d in likeD[i]:
        add_edge(N + i, N * 2 + F + d, 1)


def dfs(u, t, f, used):
    if u == t:
        return f
    used[u] = True
    for e in G[u]:
        if e.cap > 0 and not used[e.v]:
            d = dfs(e.v, t, min(f, e.cap), used)
            if d > 0:
                e.cap -= d
                G[e.v][e.rev].cap += d
                return d
    return 0


def max_flow(s, t):
    res = 0
    while True:
        used = [False] * (N * 2 + F + D + 2)
        f = dfs(s, t, INF, used)
        if f == 0:
            return res
        res += f


print(max_flow(s, t))
