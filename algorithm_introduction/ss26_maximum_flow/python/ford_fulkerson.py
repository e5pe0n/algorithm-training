from typing import List


N = 6


class Edge:
    def __init__(self, u, v, c, f):
        self.u = u
        self.v = v
        self.c = c
        self.f = f
        self.cf = c - f


def dfs_visit(_E: List[List[Edge]], u: int, t: int, pth: List[int]) -> None:
    if pth[t] >= 0 or u == t:
        return

    for e in _E[u]:
        if pth[e.v] < 0 and e.cf > 0:
            pth[e.v] = u
            dfs_visit(_E, e.v, t, pth)


def dfs(_E: List[List[Edge]], s: int, t: int) -> List[Edge]:
    pth = [-1 for i in range()]

    dfs_visit(_E, s, t, pth)

    if pth[t] < 0:
        # Augmenting path is not found
        return []
    else:
        p = []
        cur = t
        while cur != s:
            pre = pth[cur]
            p.append(_E[pre][cur])
            cur = pre
        return p


def ford_fulkerson(E: List[List[Edge]], s: int, t: int) -> None:
    global N

    Ef = [[] for _ in range(N)]
    for e in E:
        Ef[e.v].append(Edge(e.v, e.u, e.f, e.c))

    _E = [[None for _ in range(N)] for _ in range(N)]
    E_m = [[None for _ in range(N)] for _ in range(N)]
    for e in E:
        _E[e.u][e.v] = e
        E_m[e.u][e.v] = e
    for e in _E:
        _E[e.u][e.v] = e

    while True:
        p = dfs(_E, s, t)

        if len(p) == 0:
            break

        min_cf = min(p, key=lambda x: x.cf)
        for e in p:
            if _E[e.u][e.v] is not None:
                e.f += min_cf
            else:
                e.f -= min_cf


E = [
    [Edge(0, 1, 0, 16), Edge(0, 2, 0, 13)],
    [Edge(1, 3, 0, 12)],
    [Edge(2, 1, 0, 4), Edge(2, 4, 0, 14)],
    [Edge(3, 5, 0, 20)],
    [Edge(4, 3, 0, 7), Edge(4, 5, 0, 4)]
]

ford_fulkerson(E, 0, 5)
