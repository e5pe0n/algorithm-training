INF = int(1e9)


def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, v, cap, rev):
        self.v = v
        self.cap = cap
        self.rev = rev


with open("../testset/work_assignment/test2.txt", 'r') as f:
    N, M, K = map(int, ns(f).split())
    G = [[] for _ in range(N + M + 2)]

    def add_edge(u, v, cap):
        global G
        G[u].append(Edge(v, cap, len(G[v])))
        G[v].append(Edge(u, 0, len(G[u]) - 1))

    for _ in range(K):
        u, v = map(int, ns(f).split())
        add_edge(u - 1, N + v - 1, 1)


def dfs(u, t, f, used):
    global G
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


s = N + M
t = s + 1
for i in range(N):
    add_edge(s, i, 1)
for i in range(M):
    add_edge(N + i, t, 1)
res = 0
while True:
    used = [False] * (N + M + 2)
    f = dfs(s, t, INF, used)
    if f == 0:
        print(res)
        exit()
    res += f
