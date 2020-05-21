import sys
import heapq
from typing import List


I_MAX = sys.maxsize


class Vertex:
    def __init__(self, n: int):
        self.n = n
        self.adj = []
        self.distance = I_MAX
        self.pth = None  # Vertex

    def __lt__(self, other):
        return self.distance < other.distance

    def __le__(self, other):
        return self.distance <= other.distance

    def __gt__(self, other):
        return self.distance > other.distance

    def __ge__(self, other):
        return self.distance >= other.distance


def mst_prim(N: int, V: List[Vertex], weight: List[List[int]], selected: List[bool], r: int):
    q = []
    heapq.heapify(q)
    V[r].distance = 0
    heapq.heappush(q, V[r])
    while len(q) > 0:
        u = heapq.heappop(q)
        selected[u.n] = True
        for v in u.adj:
            if (not selected[v.n]) and weight[u.n][v.n] < v.distance:
                less = min(u.n, v.n)
                greater = max(u.n, v.n)
                v.distance = weight[less][greater]
                v.pth = u
                heapq.heappush(q, v)


N = 9
V = [Vertex(i) for i in range(N)]
weight = [[0 for _ in range(N)] for _ in range(N)]
selected = [False for i in range(N)]

V[0].adj = [V[1], V[7]]
V[1].adj = [V[0], V[2], V[7]]
V[2].adj = [V[1], V[3], V[5], V[8]]
V[3].adj = [V[2], V[4], V[5]]
V[4].adj = [V[3], V[5]]
V[5].adj = [V[2], V[3], V[4], V[6]]
V[6].adj = [V[5], V[7], V[8]]
V[7].adj = [V[0], V[1], V[6], V[8]]
V[8].adj = [V[2], V[6], V[7]]

weight[0][1] = 4
weight[0][7] = 8
weight[1][2] = 8
weight[1][7] = 11
weight[2][3] = 7
weight[2][5] = 4
weight[2][8] = 2
weight[3][4] = 9
weight[3][5] = 14
weight[4][5] = 10
weight[5][6] = 2
weight[6][7] = 1
weight[6][8] = 6
weight[7][8] = 7

r = 0
mst_prim(N, V, weight, selected, r)

total_weight = 0
print('edges: ', end='')
for i in range(1, N):
    total_weight += V[i].distance
    print(f'({V[i].pth.n}, {V[i].n}), ', end='')
print()
print(f'total weight: {total_weight}')

# edges: (0, 1), (5, 2), (2, 3), (3, 4), (6, 5), (7, 6), (0, 7), (2, 8),
# total weight: 37
