from math import floor


INF = 1e9


def ns(f):
    return next(f).strip()


with open("../testset/cable_master/test1.txt", 'r') as f:
    N, K = map(int, ns(f).split())
    L = list(map(float, ns(f).split()))


def C(x):
    n = 0
    for el in L:
        n += int(el / x)
    return n >= K


lb = 0.0
ub = INF
for i in range(100):
    mid = (lb + ub) / 2
    if C(mid):
        lb = mid
    else:
        ub = mid
print(f"{floor(ub * 100) / 100:.2f}")
