INF = float('inf')


def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, v, cap, cost, rev):
        self.v = v
        self.cap = cap
        self.cost = cost
        self.rev = rev


with open("../testset/evacuation_plan/test1.txt", 'r') as f:
    N, M = map(int, ns(f).split())
    B = [list(map(int, ns(f).split())) for _ in range(N)]
    C = [list(map(int, ns(f).split())) for _ in range(M)]
    E = [list(map(int, ns(f).split())) for _ in range(N)]


V = N + M + 1
g = [[INF] * V for _ in range(V)]
for j, (p, q, c) in enumerate(C):
    s = 0
    for i, (x, y, b) in enumerate(B):
        _c = abs(x - p) + abs(y - q) + 1
        g[i][N + j] = _c
        if E[i][j] > 0:
            g[N + j][i] = -_c
        s += E[i][j]
    if s > 0:
        g[N + M][N + j] = 0
    if s < c:
        g[N + j][N + M] = 0

prv = [[i] * V for i in range(V)]
for k in range(V):
    for i in range(V):
        for j in range(V):
            if g[i][j] > g[i][k] + g[k][j]:
                g[i][j] = g[i][k] + g[k][j]
                prv[i][j] = prv[k][j]
                if i == j and g[i][j] < 0:
                    used = [False] * V
                    u = i
                    while not used[u]:
                        used[u] = True
                        if u != N + M and prv[i][u] != N + M:
                            if u >= N:
                                E[prv[i][u]][u - N] += 1
                            else:
                                E[u][prv[i][u] - N] -= 1
                        u = prv[i][u]
                    print("SUBOPTIONAL")
                    for x in range(N):
                        print(" ".join([str(E[x][y]) for y in range(M)]))
                    exit()
print("OPTIONAL")
