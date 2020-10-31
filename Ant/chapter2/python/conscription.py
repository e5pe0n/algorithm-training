def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, u, v, weight):
        self.u = u
        self.v = v
        self.weight = weight


with open("../testset/conscription/test1.txt", 'r') as f:
    N, M, R = map(int, ns(f).split())
    E = []
    for _ in range(R):
        u, w, weight = map(int, ns(f).split())
        E.append(Edge(u, w + N, -weight))

par = [i for i in range(N + M)]
rnk = [0] * (N + M)


def find(u):
    if par[u] == u:
        return u
    par[u] = find(par[u])
    return par[u]


def unite(u, v):
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
    E.sort(key=lambda x: x.weight)
    res = 0
    for e in E:
        if not same(e.u, e.v):
            res += e.weight
            unite(e.u, e.v)
    return res


ans = 10000 * (N + M) + kruscal()
print(ans)
