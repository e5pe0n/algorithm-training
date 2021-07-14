from typing import List, FrozenSet, Dict
from collections import defaultdict, deque


def create_graph(words: FrozenSet[str]) -> Dict[str, List[str]]:
    graph = defaultdict(list)
    for w in words:
        for _w in words:
            if len(w) != len(_w):
                continue
            diff = 0
            for c, _c in zip(w, _w):
                if c != _c:
                    diff += 1
            if diff == 1:
                graph[w].append(_w)
                graph[_w].append(w)
    return graph


def _transform(s: str, t: str, graph: Dict[str, List[str]]) -> List[str]:
    prv1, prv2 = {}, {}
    inf = len(graph) + 1
    dist1 = {k: inf for k in graph}
    dist2 = dist1.copy()
    dist1[s] = dist2[t] = 0
    q = deque([s, t])
    collision = None
    while (q):
        u = q.popleft()
        if dist1[u] < inf and dist2[u] < inf:
            collision = u
            break
        for v in graph[u]:
            if dist1[v] > dist1[u] + 1:
                dist1[v] = dist1[u] + 1
                prv1[v] = u
                q.append(v)
            if dist2[v] > dist2[u] + 1:
                dist2[v] = dist2[u] + 1
                prv2[v] = u
                q.append(v)
    if not collision:
        return []
    r_from_a = []
    u = collision
    while u in prv1:
        r_from_a.append(prv1[u])
        u = prv1[u]
    from_b = []
    u = collision
    while u in prv2:
        from_b.append(prv2[u])
        u = prv2[u]
    return r_from_a[::-1] + [collision] + from_b


def transform(s: str, t: str, words: FrozenSet[str]) -> List[str]:
    graph = create_graph(words)
    return _transform(s, t, graph)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        s, t = ns(f).split()
        n = int(ns(f))
        words = frozenset([ns(f) for _ in range(n)])
    res = transform(s, t, words)
    print('->'.join(res))
    print()


solve("../testcases/17_22/01.txt")
solve("../testcases/17_22/02.txt")

# # ../testcases/17_22/01.txt
# DAMP->LAMP->LIMP->LIME->LIKE

# # ../testcases/17_22/02.txt
# DAMP->TAMP->TIMP->TIME->LIME->LIKE
