from collections import defaultdict
N, M = map(int, input().split())

par = list(range(N))
rnk = [0] * N

A = list(map(int, input().split()))
B = list(map(int, input().split()))


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
    if rnk[x] < rnk[y]:
        par[x] = y
    else:
        par[y] = x
        if rnk[x] == rnk[y]:
            rnk[x] += 1


def same(x, y):
    return find(x) == find(y)


for _ in range(M):
    c, d = map(int, input().split())
    unite(c - 1, d - 1)

d = defaultdict(list)
for i in range(N):
    d[find(i)].append(A[i] - B[i])
if all(list(map(lambda k: sum(d[k]) == 0, d))):
    print("Yes")
else:
    print("No")
