import heapq
from typing import List


INF = 1_000_000_000
N = 5

selected = [False] * N


class Vertex:
    def __init__(self, n):
        self.n = n
        self.dist = INF
        self.arrows = []
        self.pth = -1

    def __lt__(self, other):
        return self.dist < other.dist

    def __le__(self, other):
        return self.dist <= other.dist

    def __ge__(self, other):
        return self.dist >= other.dist

    def __gt__(self, other):
        return self.dist > other.dist


class Arrow:
    def __init__(self, dest: Vertex, weight: int):
        self.dest = dest
        self.weight = weight


def iniitial_single_source(V: List[Vertex]):
    V[0].dist = 0


def relax(u: Vertex, v: Vertex, weight: int):
    if v.dist > u.dist + weight:
        v.dist = u.dist + weight
        v.pth = u.n


def dijkstra(V: List[Vertex]):
    q = []
    heapq.heapify(q)
    iniitial_single_source(V)
    heapq.heappush(q, V[0])
    while len(q) > 0:
        u = heapq.heappop(q)
        selected[u.n] = True
        for arrow in u.arrows:
            v = arrow.dest
            if not selected[v.n]:
                relax(u, v, arrow.weight)
                heapq.heappush(q, v)


V = [Vertex(i) for i in range(N)]
V[0].arrows = [Arrow(V[1], 10), Arrow(V[3], 5)]
V[1].arrows = [Arrow(V[2], 1), Arrow(V[3], 2)]
V[2].arrows = [Arrow(V[4], 4)]
V[3].arrows = [Arrow(V[1], 3), Arrow(V[2], 9), Arrow(V[4], 2)]
V[4].arrows = [Arrow(V[0], 7), Arrow(V[2], 6)]

dijkstra(V)

for v in V:
    print('V[%d].dist: %d' % (v.n, v.dist))

# V[0].dist: 0
# V[1].dist: 8
# V[2].dist: 9
# V[3].dist: 5
# V[4].dist: 7
