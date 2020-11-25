from itertools import chain
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


with open("../testset/intervals/test3.txt", 'r') as f:
    N, K = map(int, ns(f).split())
    X = [list(map(int, ns(f).split())) for _ in range(N)]


xs = sorted(list(set(chain(*[(x[0], x[1]) for x in X]))))
m = len(xs)
s = m
t = s + 1
V = t + 1
G = [[] for _ in range(V)]


def add_edge(u, v, cap, cost):
    global G
    G[u].append(Edge(v, cap, cost, len(G[v])))
    G[v].append(Edge(u, 0, -cost, len(G[u]) - 1))


add_edge(s, 0, K, 0)
add_edge(m - 1, t, K, 0)
for i in range(m - 1):
    add_edge(i, i + 1, INF, 0)
res = 0
for a, b, w in X:
    u = xs.index(a)
    v = xs.index(b)
    add_edge(v, u, 1, w)
    add_edge(s, v, 1, 0)
    add_edge(u, t, 1, 0)
    res -= w


def min_cost_flow(s, t, f):
    res = 0
    h = [0] * V
    while f > 0:
        prevv = [0] * V
        preve = [0] * V
        dist = [INF] * V
        dist[s] = 0
        q = [(dist[s], s)]
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
        u = t
        d = f
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


res += min_cost_flow(s, t, K + N)
print(-res)
