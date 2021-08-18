from heapq import heapify, heappop, heappush
INF = float("inf")


class Edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w


N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(Edge(a, b, c))
    G[b].append(Edge(b, a, c))


def dijkstra(s):
    dist = [INF] * N
    dist[s] = 0
    q = [(0, s)]
    heapify(q)
    while q:
        d, u = heappop(q)
        if dist[u] < d:
            continue
        for e in G[u]:
            if dist[e.v] > dist[u] + e.w:
                dist[e.v] = dist[u] + e.w
                heappush(q, (dist[e.v], e.v))
    return dist


dist1 = dijkstra(0)
dist2 = dijkstra(N - 1)
print('\n'.join(map(lambda x: str(x[0] + x[1]), zip(dist1, dist2))))
