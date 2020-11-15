INF = int(1e9)


def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, v, cap, cost, rev):
        self.v = v
        self.cap = cap
        self.cost = cost
        self.rev = rev

    def __repr__(self):
        return f"Edge(v={self.v}, cap={self.cap}, cost={self.cost}, rev={self.rev})"


with open("../testset/min_cost_traffic/test1.txt", 'r') as f:
    N, M, S, T, F = map(int, ns(f).split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        u, v, cap, cost = map(int, ns(f).split())
        G[u].append(Edge(v, cap, cost, len(G[v])))
        G[v].append(Edge(u, 0, -cost, len(G[u]) - 1))


def min_cost_flow(s, t, f):
    res = 0
    while f > 0:
        prevv = [0] * N
        preve = [0] * N
        dist = [INF] * N
        dist[s] = 0
        update = True
        while update:
            update = False
            for u in range(N):
                if dist[u] == INF:
                    continue
                for i in range(len(G[u])):
                    e = G[u][i]
                    if e.cap > 0 and dist[e.v] > dist[u] + e.cost:
                        dist[e.v] = dist[u] + e.cost
                        prevv[e.v] = u
                        preve[e.v] = i
                        update = True
        if dist[t] == INF:
            return -1
        d = f
        u = t
        while u != s:
            d = min(d, G[prevv[u]][preve[u]].cap)
            u = prevv[u]
        f -= d
        res += d * dist[t]
        u = t
        while u != s:
            e = G[prevv[u]][preve[u]]
            e.cap -= d
            G[u][e.rev].cap += d
            u = prevv[u]
    return res


res = min_cost_flow(S, T, F)
print(res)
