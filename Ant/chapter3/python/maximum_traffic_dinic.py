from collections import deque


INF = int(1e9)


def ns(f):
    return next(f).strip()


def loop(i, f, g):
    while f(i):
        yield i
        i = g(i)


class Edge:
    def __init__(self, v, cap, rev):
        self.v = v
        self.cap = cap
        self.rev = rev


with open("../testset/maximum_traffic/test1.txt", 'r') as f:
    n, m, s, t = map(int, ns(f).split())
    G = [[] for _ in range(n)]
    for _ in range(m):
        u, v, cap = map(int, ns(f).split())
        G[u].append(Edge(v, cap, len(G[v])))
        G[v].append(Edge(u, 0, len(G[u]) - 1))


level = []
it = []


def bfs(s):
    global level
    level[s] = 0
    q = deque([s])
    while len(q) > 0:
        u = q.popleft()
        for e in G[u]:
            if e.cap > 0 and level[e.v] < 0:
                level[e.v] = level[u] + 1
                q.append(e.v)


def dfs(u, t, f):
    global it
    if u == t:
        return f
    while it[u] < len(G[u]):
        e = G[u][it[u]]
        if e.cap > 0 and level[u] < level[e.v]:
            d = dfs(e.v, t, min(f, e.cap))
            if d > 0:
                e.cap -= d
                G[u][e.rev].cap += d
                return d
        it[u] += 1
    return 0


res = 0
while True:
    level = [-1] * n
    bfs(s)
    if level[t] < 0:
        print(res)
        exit()
    it = [0] * n
    while (f := dfs(s, t, INF)) > 0:
        res += f
