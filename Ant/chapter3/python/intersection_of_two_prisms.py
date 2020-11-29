INF = float('inf')


def ns(f):
    return next(f).strip()


with open("../testset/intersection_of_two_prisms/test1.txt", 'r') as f:
    M, N = map(int, ns(f).split())
    C1 = [list(map(int, ns(f).split())) for _ in range(M)]
    C2 = [list(map(int, ns(f).split())) for _ in range(N)]


def width(C, x):
    lb, ub = INF, -INF
    n = len(C)
    for i in range(n):
        x1 = C[i][0]
        y1 = C[i][1]
        x2 = C[(i + 1) % n][0]
        y2 = C[(i + 1) % n][1]
        if (x1 - x) * (x2 - x) <= 0 and x1 != x2:
            y = y1 + (y2 - y1) * (x - x1) / (x2 - x1)
            lb = min(lb, y)
            ub = max(ub, y)
    return max(0.0, ub - lb)


min1, max1 = min(C1)[0], max(C1)[0]
min2, max2 = min(C2)[0], max(C2)[0]
xs = [c[0] for c in (C1 + C2)]
xs.sort()
res = 0
for i in range(len(xs) - 1):
    a = xs[i]
    b = xs[i + 1]
    c = (a + b) / 2
    if min1 <= c <= max1 and min2 <= c <= max2:
        fa = width(C1, a) * width(C2, a)
        fb = width(C1, b) * width(C2, b)
        fc = width(C1, c) * width(C2, c)
        res += (b - a) / 6 * (fa + 4 * fc + fb)
print(f"{res:.10f}")
