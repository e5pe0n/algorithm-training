from math import pi, sin, cos, radians


ST_SIZE = (1 << 15) - 1


def ns(f):
    return next(f).strip()


with open("../testset/crane/test2.txt", 'r') as f:
    N, C = map(int, ns(f).split())
    L = list(map(int, ns(f).split()))
    S = list(map(lambda x: int(x) - 1, ns(f).split()))
    A = list(map(int, ns(f).split()))


vx = [0.0] * ST_SIZE
vy = [0.0] * ST_SIZE
ang = [0.0] * ST_SIZE
prv = [pi] * N


def init(k, left, right):
    global vx, vy, ang
    ang[k] = vx[k] = 0.0
    if right - left == 1:
        vy[k] = L[left]
    else:
        chl = k * 2 + 1
        chr = k * 2 + 2
        init(chl, left, (left + right) // 2)
        init(chr, (left + right) // 2, right)
        vy[k] = vy[chl] + vy[chr]


def change(k, a, v, left, right):
    if left <= k < right - 1:
        chl = v * 2 + 1
        chr = v * 2 + 2
        m = (left + right) // 2
        change(k, a, chl, left, m)
        change(k, a, chr, m, right)
        if k < m:
            ang[v] += a
        s = sin(ang[v])
        c = cos(ang[v])
        vx[v] = vx[chl] + (c * vx[chr] - s * vy[chr])
        vy[v] = vy[chl] + (s * vx[chr] + c * vy[chr])


init(0, 0, N)
for i in range(C):
    s = S[i]
    a = radians(A[i])
    change(s, a - prv[s], 0, 0, N)
    prv[s] = a
    print(f"{vx[0]:.2f} {vy[0]:.2f}")
