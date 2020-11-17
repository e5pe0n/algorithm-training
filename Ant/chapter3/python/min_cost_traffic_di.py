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


with open("../testset/min_cost_traffic/test1.txt", 'r') as f:
    N, M, S, T, F = map(int, ns(f).split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        u, v, cap, cost = map(int, ns(f).split())
        G[u].append(Edge(v, cap, cost, len(G[v])))
        G[v].append(Edge(u, 0, -cost, len(G[u]) - 1))


def min_cost_flow(s, t, f):
    res = 0
    h = [0] * N
    while f > 0:
        prevv = [0] * N
        preve = [0] * N
        dist = [INF] * N
        dist[s] = 0
        q = [[0, s]]
        heapify(q)
        while len(q) > 0:
            p = heappop(q)
            u = p[1]
            if dist[u] < p[0]:
                continue
            for i in range(len(G[u])):
                e = G[u][i]
                if e.cap > 0 and dist[e.v] > dist[u] + e.cost + h[u] - h[e.v]:
                    dist[e.v] = dist[u] + e.cost + h[u] - h[e.v]
                    prevv[e.v] = u
                    preve[e.v] = i
                    heappush(q, [dist[e.v], e.v])
        if dist[t] == INF:
            return -1
        for u in range(N):
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


res = min_cost_flow(S, T, F)
print(res)
