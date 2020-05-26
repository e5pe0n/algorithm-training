import heapq
from typing import List
from pprint import pprint


INF = 1_000_000_000
N = 5

h = [0 if i == 0 else INF for i in range(N + 1)]
D = [[0 if j == 1 else INF for j in range(N + 1)] for _ in range(N + 1)]


class Edge:
    def __init__(self, u: int, v: int, weight: int):
        self.u = u
        self.v = v
        self.weight = weight


class Vertex:
    def __init__(self, n: int, d: int):
        self.n = n
        self.d = d

    def __lt__(self, other):
        return self.d < other.d

    def __gt__(self, other):
        return self.d > other.d


def relax(u: int, v: int, weight: int, a: List[int]) -> int:
    if a[u] < INF and a[v] > a[u] + weight:
        a[v] = a[u] + weight
    return a[v]


def bellman_ford(E: List[List[Edge]]) -> bool:
    global N, h

    for i in range(N):
        for es in E:
            for e in es:
                relax(e.u, e.v, e.weight, h)
    for es in E:
        for e in es:
            if h[e.v] > h[e.u] + e.weight:
                return False
    return True


def dijkstra(E: List[List[Edge]], V: List[Vertex], k: int, selected: List[bool]):
    global D

    q = []
    heapq.heapify(q)
    heapq.heappush(q, V[k])
    while len(q) > 0:
        u = heapq.heappop(q)
        selected[u.n] = True
        for e in E[u.n]:
            V[e.v].d = relax(u.n, e.v, e.weight, D[k])
            heapq.heappush(q, V[e.v])


def johnson(E: List[List[Edge]], V: List[Vertex]) -> bool:
    global D

    has_no_loop = bellman_ford(E)
    if not has_no_loop:
        return False

    for i in range(1, N + 1):
        for e in E[i]:
            e.weight = e.weight + h[e.u] - h[e.v]
    for i in range(1, N + 1):
        _V = V.copy()
        selected = [False] * N + 1
        dijkstra(E, _V, i, selected)
    for u in range(1, N + 1):
        for v in range(1, N + 1):
            D[u][v] = D[u][v] + h[v] - h[u]

    return True


E = [
    [Edge(0, 1, 0), Edge(0, 2, 0), Edge(0, 3, 0), Edge(0, 4, 0), Edge(0, 5, 0)],
    [Edge(1, 2, 3), Edge(1, 3, 8), Edge(1, 5, -4)],
    [Edge(2, 4, 1), Edge(2, 5, 7)],
    [Edge(3, 2, 4)],
    [Edge(4, 1, 2)],
    [Edge(5, 4, 6)]
]

V = [Vertex(0, 0), Vertex(1, 0), Vertex(2, -1), Vertex(3, -5), Vertex(4, 0), Vertex(5, -4)]

has_no_loop = johnson(E, V)
if has_no_loop:
    pprint(D)
else:
    print('Found a loop')
