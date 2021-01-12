N, M = map(int, input().split())
AB = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]

par, rnk = [], []


def init():
    global par, rnk
    par = list(range(N))
    rnk = [0] * N


def find(x):
    global par
    if x == par[x]:
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


res = 0
for i in range(M):
    init()
    for j in range(M):
        if i == j:
            continue
        unite(*AB[j])
    for i in range(N):
        find(i)
    res += int(not all(list(map(lambda x: x == par[0], par))))
print(res)
