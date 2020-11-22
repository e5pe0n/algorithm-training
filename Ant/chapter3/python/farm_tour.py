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


with open("../testset/farm_tour/test1.txt", 'r') as f:
    N, M = map(int, ns(f).split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        a, b, c = map(int, ns(f).split())
        a -= 1
        b -= 1
        G[a].append(Edge(b, 1, c, len(G[b])))
        G[b].append(Edge(a, 0, -c, len(G[a]) - 1))


def min_cost_flow(s, t, f):
    res = 0
    h = [0] * N
    while f > 0:
        prevv = [0] * N
        preve = [0] * N
        dist = [0] + [INF] * (N - 1)
        q = [(0, s)]
        heapify(q)
        while len(q) > 0:
            d, u = heappop(q)
            if d > dist[u]:
                continue
            for i, e in enumerate(G[u]):
                if e.cap > 0 and dist[e.v] > dist[u] + e.cost + h[u] - h[e.v]:
                    dist[e.v] = dist[u] + e.cost + h[u] - h[e.v]
                    prevv[e.v] = u
                    preve[e.v] = i
                    heappush(q, (dist[e.v], e.v))
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


print(min_cost_flow(0, N - 1, 2))
