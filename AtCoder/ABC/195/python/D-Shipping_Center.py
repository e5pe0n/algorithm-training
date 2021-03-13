from functools import cmp_to_key


def cmp(x, y):
    if x[1] == y[1]:
        if x[0] <= y[0]:
            return -1
        else:
            return 1
    else:
        if x[1] >= y[1]:
            return -1
        else:
            return 1


N, M, Q = map(int, input().split())
WV = sorted([list(map(int, input().split())) for _ in range(N)], key=cmp_to_key(cmp))
X = list(map(int, input().split()))
for _ in range(Q):
    L, R = map(int, input().split())
    L -= 1
    R -= 1
    xs = sorted([x for i, x in enumerate(X) if not (L <= i <= R)])
    used = [False] * len(xs)
    res = 0
    for w, v in WV:
        for i, x in enumerate(xs):
            if x >= w and not used[i]:
                used[i] = True
                res += v
                break
    print(res)
