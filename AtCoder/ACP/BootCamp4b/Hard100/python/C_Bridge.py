class Edge:
    def __init__(self, u, v):
        self.u = u
        self.v = v


par = []
rnk = []


def init(N):
    global par, rnk
    par = list(range(N))
    rnk = [0] * N


def find(x):
    global par
    if par[x] == x:
        return x
    par[x] = find(par[x])
    return par[x]


def unite(x, y):
    global par, rnk
    x = find(x)
    y = find(y)
    if x == y:
        return
    if rnk[y] > rnk[x]:
        par[x] = y
    else:
        par[y] = x
        if rnk[x] == rnk[y]:
            rnk[x] += 1


def same(x, y):
    return find(x) == find(y)


N, M = [int(x) for x in input().split()]
E = []
for _ in range(M):
    E.append(Edge(*[int(x) - 1 for x in input().split()]))

ans = M
for i in range(M):
    init(N)
    for j in range(M):
        if i != j and not same(E[j].u, E[j].v):
            unite(E[j].u, E[j].v)
    for j in range(N):
        find(j)
    if all(map(lambda x: x == par[0], par[1:N])):
        ans -= 1
print(ans)
