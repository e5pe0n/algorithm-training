from heapq import heapify, heappop, heappush


INF = float('inf')


def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, u, v, weight):
        self.u = u
        self.v = v
        self.weight = weight


with open("../testset/roadblocks/test1.txt", 'r') as f:
    N, R = map(int, ns(f).split())
    G = [[] for _ in range(N)]
    for _ in range(R):
        u, v, weight = map(int, ns(f).split())
        u -= 1
        v -= 1
        G[u].append(Edge(u, v, weight))
        G[v].append(Edge(v, u, weight))

dist1 = [INF] * N
dist2 = [INF] * N
q = [[0, 0]]
heapify(q)
while len(q) > 0:
    _d, u = heappop(q)
    if dist2[u] < _d:
        continue
    for e in G[u]:
        d = _d + e.weight
        if dist1[e.v] > d:
            dist1[e.v], d = d, dist1[u]
            heappush(q, [dist1[e.v], e.v])
        if dist2[e.v] > d and dist1[e.v] < d:
            dist2[e.v], d = d, dist2[e.v]
            heappush(q, [dist2[e.v], e.v])
print(dist2[N - 1])
