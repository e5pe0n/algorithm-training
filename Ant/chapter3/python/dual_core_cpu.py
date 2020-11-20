from collections import deque


INF = float('inf')


def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, v, cap, rev):
        self.v = v
        self.cap = cap
        self.rev = rev


with open("../testset/dual_core_cpu/test1.txt", 'r') as f:
    N, M = map(int, ns(f).split())
    AB = [list(map(int, ns(f).split())) for _ in range(N)]
    abw = []
    for _ in range(M):
        a, b, w = map(int, ns(f).split())
        abw.append([a - 1, b - 1, w])

G = [[] for _ in range(N + 2)]


def add_edge(u, v, cap):
    global G
    G[u].append(Edge(v, cap, len(G[v])))
    G[v].append(Edge(u, 0, len(G[u]) - 1))


s = N
t = s + 1
for i in range(N):
    add_edge(s, i, AB[i][1])
    add_edge(i, t, AB[i][0])
for i in range(M):
    a, b, w = abw[i]
    add_edge(a, b, w)
    add_edge(b, a, w)


def bfs(s, level):
    level[s] = 0
    q = deque([s])
    while len(q) > 0:
        u = q.popleft()
        for e in G[u]:
            if e.cap > 0 and level[e.v] < 0:
                level[e.v] = level[u] + 1
                q.append(e.v)


def dfs(u, t, f, level, it):
    if u == t:
        return f
    while it[u] < len(G[u]):
        e = G[u][it[u]]
        it[u] += 1
        if e.cap > 0 and level[e.v] > level[u]:
            d = dfs(e.v, t, min(f, e.cap), level, it)
            if d > 0:
                e.cap -= d
                G[e.v][e.rev].cap += d
                return d
    return 0


def max_flow(s, t):
    res = 0
    while True:
        level = [-1] * (N + 2)
        bfs(s, level)
        if level[t] < 0:
            return res
        it = [0] * (N + 2)
        while (f := dfs(s, t, INF, level, it)) > 0:
            res += f


print(max_flow(s, t))
