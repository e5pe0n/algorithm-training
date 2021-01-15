from collections import Counter
N, M, K = map(int, input().split())
AB = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]
CD = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(K)]

par = []
rnk = []


def init():
    global par, rnk
    par = list(range(N))
    rnk = [0] * N


def find(x):
    global par
    if x == par[x]:
        return x
    else:
        par[x] = find(par[x])
        return par[x]


def unite(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return
    if rnk[x] < rnk[y]:
        par[x] = y
    else:
        par[y] = x
        if rnk[x] == rnk[y]:
            rnk[x] += 1


def same(x, y):
    return find(x) == find(y)


init()
F = Counter()
for a, b in AB:
    unite(a, b)
    F[a] += 1
    F[b] += 1
for i in range(N):
    find(i)
G = Counter()
for i in range(N):
    G[par[i]] += 1
V = [0] * N
for i in range(N):
    V[i] = G[par[i]] - F[i] - 1
for c, d in CD:
    if same(c, d):
        V[c] -= 1
        V[d] -= 1
print(' '.join(list(map(str, V))))
