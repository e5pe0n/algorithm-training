from typing import List
from collections import deque
import sys


I_MAX = sys.maxsize


N = 8
d = [I_MAX] * N
p = [-1] * N


def BFS(V: List[List[int]], s: int):
    dq = deque([s])
    d[s] = 0
    while len(dq) > 0:
        u = dq.pop()
        for v in V[u]:
            if d[v] >= I_MAX:
                d[v] = d[u] + 1
                p[v] = u
                dq.append(v)


def print_path(p, s, v):
    if v == s:
        print(s, end='')
    elif v < 0:
        print('Path from s to v does not exist.')
    else:
        print_path(p, s, p[v])
        print(f'->{v}', end='')


V = [
    [1, 4],
    [0, 5],
    [3, 5, 6],
    [2, 6, 7],
    [0],
    [1, 2, 6],
    [2, 3, 5, 7],
    [3, 6]
]

s = 1
BFS(V, s)
print(d)
print_path(p, s, 7)
print()
