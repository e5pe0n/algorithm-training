from typing import List
from collections import deque


def bfs(graph: List[List[int]], num_of_vertices: int, src: int, dst: int) -> bool:
    visited = [False] * num_of_vertices
    visited[src] = True
    q = deque([src])
    while len(q) > 0:
        u = q.popleft()
        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                if v == dst:
                    return True
                q.append(v)
    return False


def ns(f):
    return next(f).strip()


def solve(filepath: str):
    with open(filepath) as f:
        n, m, s, t = map(int, ns(f).split())
        graph = [[] for _ in range(m)]
        for _ in range(m):
            u, v = map(int, ns(f).split())
            graph[u - 1].append(v - 1)
    print(bfs(graph, n, s - 1, t - 1))


solve("../testcases/04_01_01.txt")
solve("../testcases/04_01_02.txt")
solve("../testcases/04_01_03.txt")

# True
# False
# True
