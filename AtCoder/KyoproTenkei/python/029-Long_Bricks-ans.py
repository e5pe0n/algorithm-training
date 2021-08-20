from sys import setrecursionlimit
setrecursionlimit(10**9)

W, N = map(int, input().split())
LR = [map(lambda x: int(x) - 1, input().split()) for _ in range(N)]

sz = 1
while sz < W:
    sz *= 2


dat = [0] * (sz * 2)
lazy = [0] * (sz * 2)


def push(k):
    global dat, lazy
    if k * 2 + 2 < len(lazy):
        lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k])
        lazy[k * 2 + 2] = max(lazy[k * 2 + 2], lazy[k])
    dat[k] = max(dat[k], lazy[k])
    lazy[k] = 0


def update(a, b, x, k, left, right):
    global dat, lazy
    # update values in range [a, b)
    push(k)
    if right <= a or b <= left:
        return
    elif a <= left and right <= b:
        lazy[k] = x
        push(k)
    else:
        update(a, b, x, k * 2 + 1, left, (left + right) // 2)
        update(a, b, x, k * 2 + 2, (left + right) // 2, right)
        dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2])


def range_max(a, b, k, left, right):
    global dat, lazy
    # get the max value in range [a, b)
    push(k)
    if right <= a or b <= left:
        return 0
    if a <= left and right <= b:
        return dat[k]
    lc = range_max(a, b, k * 2 + 1, left, (left + right) // 2)
    rc = range_max(a, b, k * 2 + 2, (left + right) // 2, right)
    return max(lc, rc)


for L, R in LR:
    h = range_max(L, R + 1, 0, 0, sz) + 1
    update(L, R + 1, h, 0, 0, sz)
    print(h)
