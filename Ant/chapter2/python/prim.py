from heapq import heapify, heappop, heappush


def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, u, v, weight):
        self.u = u
        self.v = v
        self.weight = weight


with open("../testset/minimum_spanning_tree/test1.txt", 'r') as f:
    N, K = map(int, ns(f).split())
    G = [[] for _ in range(N)]
    for _ in range(K):
        u, v, weight = map(int, ns(f).split())
        u -= 1
        v -= 1
        G[u].append(Edge(u, v, weight))
        G[v].append(Edge(v, u, weight))

used = [False] * N


def prim():
    global used
    res = 0
    used[0] = True
    q = [[e.weight, e.v] for e in G[0]]
    heapify(q)
    while len(q) > 0:
        p = heappop(q)
        u = p[1]
        if used[u]:
            continue
        used[u] = True
        res += p[0]
        for e in G[u]:
            if not used[e.v]:
                heappush(q, [e.weight, e.v])
    return res


ans = prim()
print(ans)
