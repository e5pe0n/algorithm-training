from bisect import bisect_left


INF = float('inf')


def ns(f):
    return next(f).strip()


with open("../testset/huge_knapsack/test1.txt", 'r') as f:
    n, W = map(int, ns(f).split())
    w = list(map(int, ns(f).split()))
    v = list(map(int, ns(f).split()))


n2 = n // 2
ps = []
for i in range(1 << n2):
    sw, sv = 0, 0
    for j in range(n2):
        if i >> j & 1:
            sw += w[j]
            sv += v[j]
    ps.append([sw, sv])
ps.sort()
m = 1
for i in range(1, 1 << n2):
    if ps[m - 1][1] < ps[i][1]:
        ps[m] = ps[i]
        m += 1
res = 0
for i in range(1 << (n - n2)):
    sw, sv = 0, 0
    for j in range(n - n2):
        if i >> j & 1:
            sw += w[n2 + j]
            sv += w[n2 + j]
    if sw <= W:
        tv = ps[bisect_left(ps, [W - sw, INF], 0, m) - 1][1]
        res = max(res, sv + tv)
print(res)
