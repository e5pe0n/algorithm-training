from heapq import heapify, heappop, heappush
INF = float('inf')


class Edge:
    def __init__(self, u, v, weight):
        self.u = u
        self.v = v
        self.weight = weight


N, M = map(int, input().split())
G1 = [[] for _ in range(N)]
G2 = [[] for _ in range(N)]
ABC = []
for i in range(M):
    A, B, C = map(int, input().split())
    A -= 1
    B -= 1
    G1[A].append(Edge(A, B, C))
    G2[B].append(Edge(B, A, C))
    ABC.append((A, B, C))


def dijkstra(s, G):
    d = [INF] * N
    d[s] = 0
    q = [(0, s)]
    heapify(q)
    while len(q):
        _d, u = heappop(q)
        if d[u] < _d:
            continue
        for e in G[u]:
            if d[e.v] > d[u] + e.weight:
                d[e.v] = d[u] + e.weight
                heappush(q, (d[e.v], e.v))
    return d


for i in range(N):
    res = INF
    lst = [c for a, b, c in ABC if a == i and b == i]
    if lst:
        res = min(res, min(lst))
    d1 = dijkstra(i, G1)
    d2 = dijkstra(i, G2)
    lst = [_d1 + _d2 for j, (_d1, _d2) in enumerate(zip(d1, d2)) if j != i]
    if lst:
        res = min(res, min(lst))
    if res == INF:
        res = -1
    print(res)
