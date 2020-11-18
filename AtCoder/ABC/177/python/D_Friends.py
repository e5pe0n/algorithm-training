from collections import Counter


N, M = map(int, input().split())

par = [i for i in range(N)]
rnk = [0] * N


def find(x):
    global par
    if x == par[x]:
        return x
    par[x] = find(par[x])
    return par[x]


def unite(x, y):
    global rnk, par
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


for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    if not same(a, b):
        unite(a, b)

for i in range(N):
    find(i)

res = Counter(par).most_common(1)[0][1]
print(res)
