from heapq import heapify, heappop, heappush


INF = float('inf')


def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, v, cap, cost, rev):
        self.v = v
        self.cap = cap
        self.cost = cost
        self.rev = rev


with open("../testset/the_windys/test3.txt", 'r') as f:
    N, M = map(int, ns(f).split())
    Z = [list(map(int, ns(f).split())) for _ in range(N)]


s = (M + 1) * N
t = s + 1
V = t + 1
G = [[] for _ in range(V)]


def add_edge(u, v, cap, cost):
    global G
    G[u].append(Edge(v, cap, cost, len(G[v])))
    G[v].append(Edge(u, 0, -cost, len(G[u]) - 1))


for i in range(N):
    add_edge(s, i, 1, 0)


for j in range(M):
    for k in range(N):
        add_edge(N + j * N + k, t, 1, 0)
        for i in range(N):
            add_edge(i, N + j * N + k, 1, (k + 1) * Z[i][j])


def min_cost_flow(s, t, f):
    res = 0
    h = [0] * V
    while f > 0:
        prevv = [0] * V
        preve = [0] * V
        dist = [INF] * V
        dist[s] = 0
        q = [(0, s)]
        heapify(q)
        while len(q) > 0:
            d, u = heappop(q)
            if dist[u] < d:
                continue
            for i, e in enumerate(G[u]):
                if e.cap > 0 and dist[e.v] > dist[u] + e.cost + h[u] - h[e.v]:
                    dist[e.v] = dist[u] + e.cost + h[u] - h[e.v]
                    prevv[e.v] = u
                    preve[e.v] = i
                    heappush(q, (dist[e.v], e.v))
        if dist[t] == INF:
            return -1
        for u in range(V):
            h[u] += dist[u]
        d = f
        u = t
        while u != s:
            d = min(d, G[prevv[u]][preve[u]].cap)
            u = prevv[u]
        f -= d
        res += d * h[t]
        u = t
        while u != s:
            e = G[prevv[u]][preve[u]]
            e.cap -= d
            G[u][e.rev].cap += d
            u = prevv[u]
    return res


print(f"{min_cost_flow(s, t, N) / N:.6f}")
