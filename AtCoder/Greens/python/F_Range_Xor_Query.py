N, Q = map(int, input().split())
A = list(map(int, input().split()))

n = 1
while n < N:
    n *= 2

dat = [0] * (1 << 22)


def update(k, a):
    global dat
    k += n - 1
    dat[k] ^= a
    while k > 0:
        k = (k - 1) // 2
        dat[k] = dat[k * 2 + 1] ^ dat[k * 2 + 2]


def query(a, b, k, left, right):
    if right <= a or b <= left:
        return 0
    if a <= left and right <= b:
        return dat[k]
    else:
        vl = query(a, b, k * 2 + 1, left, (left + right) // 2)
        vr = query(a, b, k * 2 + 2, (left + right) // 2, right)
        return vl ^ vr


for i, a in enumerate(A):
    update(i, a)
res = []
for _ in range(Q):
    T, X, Y = map(int, input().split())
    if T == 1:
        X -= 1
        update(X, Y)
    else:
        X -= 1
        res.append(query(X, Y, 0, 0, n))
print('\n'.join(list(map(str, res))))
