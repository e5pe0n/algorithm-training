EPS = 1e-10
g = 9.8


def ns(f):
    return next(f).strip()


with open("../testset/white_bird/test4.txt", 'r') as f:
    N, V = map(int, ns(f).split())
    X, Y = map(int, ns(f).split())
    O = [list(map(int, ns(f).split())) for _ in range(N)]


def calc(vy, t):
    return vy * t - g * t * t / 2.0


def cmp(lb, ub, a):
    if a < lb + EPS:
        return -1
    elif a > ub - EPS:
        return 1
    return 0


def check(qx, qy):
    a = g * g / 4
    b = g * qy - V * V
    c = qx * qx + qy * qy

    D = b * b - 4 * a * c
    if D < 0 and D > -EPS:
        D = 0
    if D < 0:
        return False
    for d in (-1, 1):
        t2 = (-b + d * (D ** 0.5)) / (2 * a)
        if t2 <= 0:
            continue
        t = t2 ** 0.5
        vx = qx / t
        vy = (qy + g * t * t / 2) / t

        yt = calc(vy, X / vx)
        if yt < Y - EPS:
            continue
        ok = True
        for L, B, R, T in O:
            if L >= X:
                continue
            if R == X and Y <= T and B <= yt:
                ok = False
            yL = cmp(B, T, calc(vy, L / vx))
            yR = cmp(B, T, calc(vy, R / vx))
            xH = cmp(L, R, vx * (vy / g))
            yH = cmp(B, T, calc(vy, vy / g))
            if xH == 0 and yH >= 0 and yL <= 0:
                ok = False
            if yL * yR <= 0:
                ok = False
        if ok:
            return True
    return False


for i in range(N):
    O[i][2] = min(O[i][2], X)

ok = check(X, Y)
for L, B, R, T in O:
    ok |= check(L, T)
    ok |= check(R, T)
if ok:
    print("Yes")
else:
    print("No")
