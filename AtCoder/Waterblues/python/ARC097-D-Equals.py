N, M = map(int, input().split())
P = list(map(lambda x: int(x) - 1, input().split()))

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


def same(x, y):
    return find(x) == find(y)


for _ in range(M):
    x, y = map(lambda x: int(x) - 1, input().split())
    unite(x, y)
res = 0
for i in range(N):
    if same(i, P[i]):
        res += 1
print(res)
