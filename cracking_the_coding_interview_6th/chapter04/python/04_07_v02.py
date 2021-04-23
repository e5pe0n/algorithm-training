from collections import deque
from typing import List


def dfs(u, graph: List[List[int]], q: deque, added: List[bool], used: List[bool]) -> bool:
    res = True
    for v in graph[u]:
        if used[v]:
            return False
        if added[v]:
            continue
        used[v] = True
        res &= dfs(v, graph, q, added, used)
        used[v] = False
    q.append(u)
    added[u] = True
    return res


def get_build_order(n: int, graph: List[List[str]]) -> List[int]:
    q = deque()
    added = [False] * n
    for u in range(n):
        if added[u]:
            continue
        used = [False] * n
        used[u] = True
        if not dfs(u, graph, q, added, used):
            return []
    added = [False] * n
    res = [0] * n
    idx = n - 1
    while q:
        u = q.popleft()
        if not added[u]:
            res[idx] = u
            idx -= 1
            added[u] = True
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        n, m = map(int, ns(f).split())
        graph = [[] for _ in range(n)]
        for _ in range(m):
            u, v = map(int, ns(f).split())
            graph[u - 1].append(v - 1)
    res = get_build_order(n, graph)
    print(" ".join(list(map(lambda x: str(x + 1), res))) if res else "error")
    print()


solve("../testcases/04_07/01.txt")
solve("../testcases/04_07/02.txt")
solve("../testcases/04_07/03.txt")
solve("../testcases/04_07/04.txt")
solve("../testcases/04_07/05.txt")
solve("../testcases/04_07/06.txt")

# # ../testcases/04_07/01.txt
# 6 5 2 1 4 3

# # ../testcases/04_07/02.txt
# error

# # ../testcases/04_07/03.txt
# 8 3 2 1 5 12 9 4 7 6 10 11

# # ../testcases/04_07/04.txt
# error

# # ../testcases/04_07/05.txt
# 2 1

# # ../testcases/04_07/06.txt
# error
