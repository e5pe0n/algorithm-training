from heapq import heapify, heappop, heappush

INF = float('inf')


class Edge:
    def __init__(self, u, v, weight, k):
        self.u = u
        self.v = v
        self.weight = weight
        self.k = k


N, M, X, Y = map(int, input().split())
X -= 1
Y -= 1
G = [[] for _ in range(N)]
for _ in range(M):
    a, b, t, k = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(Edge(a, b, t, k))
    G[b].append(Edge(b, a, t, k))


dist = [INF] * N
dist[X] = 0


def dijkstra():
    global dist
    q = [(0, X)]
    heapify(q)
    while q:
        d, u = heappop(q)
        if dist[u] < d:
            continue
        for e in G[u]:
            w = e.weight + (dist[u] + e.k - 1) // e.k * e.k
            if dist[e.v] > w:
                dist[e.v] = w
                heappush(q, (dist[e.v], e.v))


dijkstra()
res = dist[Y]
if res == INF:
    res = -1
print(res)
