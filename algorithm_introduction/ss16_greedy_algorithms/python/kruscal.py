from collections import namedtuple
from typing import List

par = []
rnk = []


def init(n: int):
    global par, rnk

    par = list(range(n))
    rnk = [0] * n


def find(x: int) -> int:
    global par, rnk

    if par[x] == x:
        return x
    par[x] = find(par[x])
    return par[x]


def unite(x: int, y: int):
    global par, rnk

    x = find(x)
    y = find(y)
    if x == y:
        return

    if rnk[x] < rnk[y]:
        par[x] = y
    else:
        par[y] = x
        if rnk[x] == rnk[y]:
            rnk[x] += 1


def same(x: int, y: int):
    return find(x) == find(y)


Edge = namedtuple('Edge', ('u', 'v', 'weight'))


def kruscal(es: List[Edge]) -> List[Edge]:
    init(len(es))
    es.sort(key=lambda x: x.weight)
    res = []
    for e in es:
        if not same(e.u, e.v):
            unite(e.u, e.v)
            res.append(e)
    return res


es = [
    Edge(0, 1, 6),
    Edge(0, 2, 15),
    Edge(1, 3, 10),
    Edge(2, 3, 1),
    Edge(3, 4, 5),
    Edge(2, 4, 4),
    Edge(3, 5, 9),
    Edge(4, 7, 3),
    Edge(5, 6, 14),
    Edge(5, 7, 8),
    Edge(6, 7, 12),
    Edge(4, 8, 7),
    Edge(6, 8, 13)
]

res = kruscal(es)
total = sum(e.weight for e in res)
print(f'edges: {res}')
print(f'total weight: {total}')

"""
edges: [Edge(u=2, v=3, weight=1), Edge(u=4, v=7, weight=3), Edge(u=2, v=4, weight=4), Edge(u=0, v=1, weight=6), Edge(u=4, v=8, weight=7), Edge(u=5, v=7, weight=8), Edge(u=1, v=3, weight=10), Edge(u=6, v=7, weight=12)]
total weight: 51
"""
