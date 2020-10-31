def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, u, v, weight):
        self.u = u
        self.v = v
        self.weight = weight


with open("../testset/minimum_spanning_tree/test1.txt", 'r') as f:
    N, K = map(int, ns(f).split())
    E = []
    for _ in range(K):
        u, v, weight = map(int, ns(f).split())
        E.append(Edge(u - 1, v - 1, weight))

par = [i for i in range(N)]
rnk = [0] * N


def find(u):
    global par
    if par[u] == u:
        return u
    par[u] = find(par[u])
    return par[u]


def unite(u, v):
    global par, rnk
    u = find(u)
    v = find(v)
    if u == v:
        return
    if rnk[u] < rnk[v]:
        par[u] = v
    else:
        par[v] = u
        if rnk[u] == rnk[v]:
            rnk[u] += 1


def same(u, v):
    return find(u) == find(v)


def kruscal():
    res = 0
    E.sort(key=lambda x: x.weight)
    for e in E:
        if not same(e.u, e.v):
            res += e.weight
            unite(e.u, e.v)
    return res


ans = kruscal()
print(ans)
