from collections import Counter
MOD = 998244353
N, K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]

par, rnk = [], []


def init():
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


init()
for i in range(N - 1):
    for j in range(1, N):
        f = True
        for k in range(N):
            if A[i][k] + A[j][k] > K:
                f = False
        if f:
            unite(i, j)
C = Counter()
for i in range(N):
    C[find(i)] += 1
res = 1
for v in C.values():
    for i in range(1, v + 1):
        res = res * i % MOD
init()
for i in range(N - 1):
    for j in range(1, N):
        f = True
        for k in range(N):
            if A[k][i] + A[k][j] > K:
                f = False
        if f:
            unite(i, j)
C = Counter()
for i in range(N):
    C[find(i)] += 1
for v in C.values():
    for i in range(1, v + 1):
        res = res * i % MOD
print(res)
