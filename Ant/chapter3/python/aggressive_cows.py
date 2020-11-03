INF = int(1e9)


def ns(f):
    return next(f).strip()


with open("../testset/aggressive_cows/test1.txt", 'r') as f:
    N, M = map(int, ns(f).split())
    x = list(map(int, ns(f).split()))


def C(d):
    last = 0
    for _ in range(M - 1):
        crt = last + 1
        while crt < N and x[crt] - x[last] < d:
            crt += 1
        if crt == N:
            return False
        last = crt
    return True


x.sort()
lb = 0
ub = INF
while ub - lb > 1:
    mid = (ub + lb) // 2
    if C(mid):
        lb = mid
    else:
        ub = mid
print(lb)
