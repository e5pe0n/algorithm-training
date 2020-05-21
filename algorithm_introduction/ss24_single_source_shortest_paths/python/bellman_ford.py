import sys
from typing import List

INF = sys.maxsize
N = 5
dist = []
pth = []


def initialize_single_source():
    global INF, N, dist, pth

    dist = [INF] * N
    pth = [-1] * N

    dist[0] = 0


class Edge:
    def __init__(self, u: int, v: int, weight: int):
        self.u = u
        self.v = v
        self.weight = weight


def relax(u: int, v: int, weight: int):
    global dist, pth

    if dist[v] > dist[u] + weight:
        dist[v] = dist[u] + weight
        pth[v] = u


def bellman_ford(E: List[Edge]) -> bool:
    global N

    initialize_single_source()

    for _ in range(N):
        for e in E:
            relax(e.u, e.v, e.weight)

    for e in E:
        if dist[e.v] > dist[e.u] + e.weight:
            return False
    return True


def print_path(pth: List[int], s: int, v: int):
    if s == v:
        print(s, end='')
    elif v < 0:
        print(f'\nPath from {s} to {v} does not exist.')
    else:
        print_path(pth, s, pth[v])
        print(f'->{v}', end='')


E = [
    Edge(0, 1, 6),
    Edge(0, 3, 7),
    Edge(1, 2, 5),
    Edge(1, 3, 8),
    Edge(1, 4, -4),
    Edge(2, 1, -2),
    Edge(3, 2, -3),
    Edge(3, 4, 9),
    Edge(4, 0, 2),
    Edge(4, 2, 7)
]

has_no_loop = bellman_ford(E)
if has_no_loop:
    print_path(pth, 0, 4)
    print()
else:
    print('Found a loop.\n')

# 0->3->2->1->4
