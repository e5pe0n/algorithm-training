from typing import List


class Edge:
    def __init__(self, u, v, weight):
        self.u = u
        self.v = v
        self.weight = weight

    def __str__(self):
        return f'(u: {self.u}, v: {self.v}, weight: {self.weight})'


N = 9
p = []
rnk = []


def init(N: int):
    global p, rnk

    p = [i for i in range(N)]
    rnk = [0] * N


def find(x: int, y: int) -> int:
    global p

    if (p[x] == x):
        return x
    else:
        p[x] = find(p[x])
        return p[x]


def union(x: int, y: int):
    global p, rnk

    x = find(x)
    y = find(y)
    if (x == y):
        return

    if rnk[x] > rnk[y]:
        p[y] = x
    else:
        p[x] = y
        if rnk[x] == rnk[y]:
            rnk[y] += 1


def same(x: int, y: int) -> bool:
    return find(x) == find(y)


def mst_kruscal(E: List[Edge], N: int) -> List[Edge]:
    A = []
    init(N)
    E.sort(key=lambda x: x.weight)
    for e in E:
        if not same(e.u, e.v):
            A.append(e)
            union(e.u, e.v)
    return A


E = [
    Edge(0, 1, 4), Edge(0, 7, 8), Edge(1, 7, 11), Edge(1, 2, 8), Edge(2, 8, 2), Edge(2, 5, 4), Edge(2, 3, 7),
    Edge(3, 5, 14), Edge(3, 4, 9), Edge(4, 5, 10), Edge(5, 6, 2), Edge(6, 8, 6), Edge(6, 7, 1), Edge(7, 8, 7)
]

A = mst_kruscal(E, N)
total = 0
for a in A:
    total += a.weight
    print(a)
print('total weight: %d' % total)
