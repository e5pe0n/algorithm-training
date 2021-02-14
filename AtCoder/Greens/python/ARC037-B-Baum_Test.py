from collections import Counter
N, M = map(int, input().split())
UV = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]

par = list(range(N))
rnk = [0] * N


def find(x):
    global par
    if par[x] == x:
        return x
    par[x] = find(par[x])
    return par[x]


def unite(x, y):
    global rnk, par
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


for u, v in UV:
    unite(u, v)
C = Counter()
for i in range(N):
    C[find(i)] += 1
C2 = Counter()
for u, v in UV:
    C2[find(u)] += 1
res = 0
for k, v in C.most_common():
    e = C2[k]
    if v - 1 == e:
        res += 1
print(res)
