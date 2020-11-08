from bisect import bisect


ST_SIZE = (1 << 18) - 1


def ns(f):
    return next(f).strip()


with open("../testset/k_th_number/test1.txt", 'r') as f:
    N, M = map(int, ns(f).split())
    A = list(map(int, ns(f).split()))
    Q = [list(map(int, ns(f).split())) for _ in range(M)]


_A = sorted(A)
dat = [[] for _ in range(ST_SIZE)]


def init(k, left, right):
    global dat
    if right - left == 1:
        dat[k].append(A[left])
    else:
        lch = k * 2 + 1
        rch = k * 2 + 2
        init(lch, left, (left + right) // 2)
        init(rch, (left + right) // 2, right)
        dat[k] = sorted(dat[lch] + dat[rch])


def query(i, j, x, k, left, right):
    if j <= left or right <= i:
        return 0
    elif i <= left and right <= j:
        return bisect(dat[k], x)
    else:
        lc = query(i, j, x, k * 2 + 1, left, (left + right) // 2)
        rc = query(i, j, x, k * 2 + 2, (left + right) // 2, right)
        return lc + rc


init(0, 0, N)
for q in Q:
    left, right, k = q
    left -= 1

    lb = -1
    ub = N - 1
    while ub - lb > 1:
        md = (ub + lb) // 2
        c = query(left, right, _A[md], 0, 0, N)
        if c >= k:
            ub = md
        else:
            lb = md
    print(_A[ub])
