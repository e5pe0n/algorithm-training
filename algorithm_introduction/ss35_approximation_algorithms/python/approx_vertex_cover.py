from typing import List


class Edge:
    def __init__(self, u: int, v: int):
        self.u = u
        self.v = v


def approx_vertex_cover(E: List[Edge]) -> List[Edge]:
    E = E.copy()
    C = []
    while len(E) > 0:
        e = E.pop()
        C += [e.u, e.v]
        _E = E.copy()
        E = [_e for _e in _E if _e.u != e.u and _e.u != e.v and _e.v != e.u and _e.v != e.v]
    return C


E = [
    Edge(0, 1),
    Edge(1, 2),
    Edge(2, 3),
    Edge(2, 4),
    Edge(3, 4),
    Edge(3, 5),
    Edge(4, 5),
    Edge(3, 6)
]

C = approx_vertex_cover(E)
print(C)
