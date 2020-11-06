INF = float('inf')


def ns(f):
    return next(f).strip()


with open("../testset/segment_tree_rmq/test1.txt", 'r') as f:
    N = int(ns(f))
    X = list(map(int, ns(f).split()))

n = 1
while n < N:
    n *= 2
dat = [INF] * (n * 2 - 1)


def update(k, a):
    global dat
    k += n - 1
    dat[k] = a
    while k > 0:
        k = (k - 1) // 2
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2])


def query(a, b, k, left, right):
    if right <= a or b <= left:
        return INF
    if a <= left and right <= b:
        return dat[k]
    else:
        vl = query(a, b, k * 2 + 1, left, (left + right) // 2)
        vr = query(a, b, k * 2 + 2, (left + right) // 2, right)
        return min(vl, vr)


for i, x in enumerate(X):
    update(i, x)
print(query(0, 7, 0, 0, n))  # 1
print(query(2, 6, 0, 0, n))  # 4
print(query(7, 8, 0, 0, n))  # 2
