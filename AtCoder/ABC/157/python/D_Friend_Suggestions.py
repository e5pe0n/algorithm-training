from collections import Counter


N, M, K = map(int, input().split())
A = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]
C = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(K)]

par = list(range(N))
rnk = [0] * N


def find(x):
    global par
    if x == par[x]:
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
        par[x] = par[y]
    else:
        par[y] = x
        if rnk[x] == rnk[y]:
            rnk[x] += 1


def same(x, y):
    return find(x) == find(y)


F = [0] * N
G = [0] * N

for a, b in A:
    unite(a, b)
    F[a] += 1
    F[b] += 1
for i in range(N):
    find(i)

cnt = Counter()
for i in range(N):
    cnt[par[i]] += 1

for c, d in C:
    if same(c, d):
        G[c] += 1
        G[d] += 1

res = [str(max(0, cnt[par[i]] - 1 - F[i] - G[i])) for i in range(N)]
print(' '.join(res))
