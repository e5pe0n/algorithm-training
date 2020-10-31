INF = float('inf')


def ns(f):
    return next(f).strip()


with open("../testset/layout/test1.txt", 'r') as f:
    N, ML, MD = map(int, ns(f).split())
    L = []
    for _ in range(ML):
        al, bl, dl = map(int, ns(f).split())
        L.append([al - 1, bl - 1, dl])
    D = []
    for _ in range(MD):
        ad, bd, dd = map(int, ns(f).split())
        D.append([ad - 1, bd - 1, dd])

d = [0] + [INF] * (N - 1)
for k in range(N):
    for i in range(N - 1):
        if d[i + 1] < INF:
            d[i] = min(d[i], d[i + 1])
    for al, bl, dl in L:
        if d[al] < INF:
            d[bl] = min(d[bl], d[al] + dl)
    for ad, bd, dd in D:
        if d[bd] < INF:
            d[ad] = min(d[ad], d[bd] - dd)

res = d[N - 1]
if d[0] < 0:
    res = -1
elif res == INF:
    res = -2
print(res)
