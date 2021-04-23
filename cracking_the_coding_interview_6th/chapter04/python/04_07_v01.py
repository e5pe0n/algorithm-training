from collections import deque
from typing import List


class Edge:
    def __init__(self, u, v):
        self.u = u
        self.v = v
        self.used = False


def get_build_order(n: int, graph: List[List[int]], edges: List[Edge]) -> List[int]:
    build_order = [-1] * n
    order = 0
    for i in range(n):
        q = deque([i])
        while q:
            u = q.popleft()
            if build_order[u] >= 0:
                continue
            buildable = True
            for j in graph[u]:
                if edges[j].v == u and not edges[j].used:
                    buildable = False
            if buildable:
                build_order[u] = order
                order += 1
                for j in graph[u]:
                    if edges[j].u == u:
                        edges[j].used = True
                        q.append(edges[j].v)
    res = [0] * n
    for i in range(n):
        if build_order[i] < 0:
            return []
        res[build_order[i]] = i
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        n, m = map(int, ns(f).split())
        graph = [[] for _ in range(n)]
        edges = [None for _ in range(m)]
        for i in range(m):
            u, v = map(lambda x: int(x) - 1, ns(f).split())
            edges[i] = Edge(u, v)
            graph[u].append(i)
            graph[v].append(i)
    res = get_build_order(n, graph, edges)
    print(" ".join(list(map(lambda x: str(x + 1), res))) if res else "error")
    print()


# solve("../testcases/04_07/01.txt")
# solve("../testcases/04_07/02.txt")
# solve("../testcases/04_07/03.txt")
# solve("../testcases/04_07/04.txt")
# solve("../testcases/04_07/05.txt")
# solve("../testcases/04_07/06.txt")

# # ../testcases/04_07/01.txt
# 5 6 2 1 4 3

# # ../testcases/04_07/02.txt
# error

# # ../testcases/04_07/03.txt
# 2 1 3 5 12 9 8 4 7 6 10 11

# # ../testcases/04_07/04.txt
# error

# # ../testcases/04_07/05.txt
# 1 2

# # ../testcases/04_07/06.txt
# error
