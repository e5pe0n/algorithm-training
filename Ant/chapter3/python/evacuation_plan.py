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

s = N + M
t = s + 1
V = N + M + 2
G = [[] for _ in range(V)]


def add_edge(u, v, cap, cost):
    global G
    G[u].append(Edge(v, cap, cost, len(G[v])))
    G[v].append(Edge(u, 0, -cost, len(G[u]) - 1))


cost = 0
for i in range(N):
    for j in range(M):
        x, y, b = B[i]
        p, q, c = C[i]
        _c = abs(x - p) + abs(y - q) + 1
        cost += _c * E[i][j]

for i in range(N):
    add_edge
