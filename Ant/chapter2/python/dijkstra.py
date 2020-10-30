from heapq import heapify, heappop, heappush


INF = float('inf')


def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, u, v, weight):
        self.u = u
        self.v = v
        self.weight = weight


with open("../testset/single_source_shortest_path/test1.txt", 'r') as f:
    N, K, S, T = map(int, ns(f).split())
    S -= 1
    T -= 1
    G = [[] for _ in range(N)]
    for _ in range(K):
        u, v, weight = map(int, ns(f).split())
        u -= 1
        v -= 1
        G[u].append(Edge(u, v, weight))
        G[v].append(Edge(v, u, weight))

dist = [INF] * N
dist[S] = 0
path = [-1] * N


def dijkstra():
    global dist, path
    q = [[0, S]]
    heapify(q)
    while len(q) > 0:
        p = heappop(q)
        u = p[1]
        if dist[u] < p[0]:
            continue
        for e in G[u]:
            if dist[e.v] > dist[u] + e.weight:
                dist[e.v] = dist[u] + e.weight
                path[e.v] = u
                heappush(q, [dist[e.v], e.v])


def _print_path(s, v):
    if s == v:
        print(s + 1, end='')
    elif v < 0:
        print('\nNo path', end='')
    else:
        _print_path(s, path[v])
        print(f"->{v + 1}", end='')


def print_path(s, v):
    _print_path(s, v)
    print()


dijkstra()
print(f"shortest distance={dist[T]}")
print("shortest path=", end='')
print_path(S, T)

# shortest distance=16
# shortest path=1->3->4->6->5->7
