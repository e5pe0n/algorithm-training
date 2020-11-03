INF = 1e18


def ns(f):
    return next(f).strip()


with open("../testset/mean_maximization/test1.txt", 'r') as f:
    N, K = map(int, ns(f).split())
    P = [list(map(int, ns(f).split())) for _ in range(N)]


def C(x):
    Y = list(map(lambda p: p[1] - x * p[0], P))
    Y.sort()
    return sum(Y[N - K:]) >= 0


lb = 0.0
ub = INF
for i in range(100):
    mid = (lb + ub) / 2
    if C(mid):
        lb = mid
    else:
        ub = mid
print(f"{lb:.2f}")
