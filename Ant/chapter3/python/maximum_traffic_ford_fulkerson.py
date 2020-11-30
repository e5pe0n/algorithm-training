INF = int(1e9)


def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, v, cap, rev):
        self.v = v
        self.cap = cap
        self.rev = rev


with open("../testset/maximum_traffic/test1.txt", 'r') as f:
    n, m, s, t = map(int, ns(f).split())
    G = [[] for _ in range(n)]

    def add_edge(u, v, cap):
        global G
        G[u].append(Edge(v, cap, len(G[v])))
        G[v].append(Edge(u, 0, len(G[u]) - 1))

    for _ in range(m):
        add_edge(*map(int, ns(f).split()))


def dfs(u, t, f, used):
    if u == t:
        return f
    used[u] = True
    for e in G[u]:
        if not used[e.v] and e.cap > 0:
            d = dfs(e.v, t, min(f, e.cap), used)
            if d > 0:
                e.cap -= d
                G[e.v][e.rev].cap += d
                return d
    return 0


def max_flow(s, t):
    res = 0
    while True:
        used = [False] * n
        f = dfs(s, t, INF, used)
        if f == 0:
            return res
        res += f


print(max_flow(s, t))
