N, M, K = map(int, input().split())
X = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]
Y = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(K)]


par = [i for i in range(N)]
rnk = [0] * N

CC1 = [0] * N
CC2 = [0] * N


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
    if rnk[y] > rnk[x]:
        par[x] = y
    else:
        par[y] = x
        if rnk[x] == rnk[y]:
            rnk[x] += 1


def same(x, y):
    return find(x) == find(y)


for x in X:
    unite(x[0], x[1])

for i in range(N):
    p = find(i)
    CC1[p] += 1

for i in range(N):
    CC2[i] = CC1[par[i]] - 1

for x in X:
    CC2[x[0]] -= 1
    CC2[x[1]] -= 1

for y in Y:
    if same(y[0], y[1]):
        CC2[y[0]] -= 1
        CC2[y[1]] -= 1

print(" ".join(map(str, CC2)))
