def ns(f):
    return next(f).strip()


with open("../testset/face_the_right_way/test1.txt", 'r') as f:
    N = int(ns(f))
    d = list(map(lambda x: 1 if x == 'B' else 0, ns(f)))


def calc(k):
    f = [0] * N
    s = 0
    res = 0
    for i in range(N - k + 1):
        if (d[i] + s) % 2 != 0:
            f[i] = 1
            res += 1
        s += f[i]
        if i - k + 1 >= 0:
            s -= f[i - k + 1]
    for i in range(N - k + 1, N):
        if (d[i] + s) % 2 != 0:
            return -1
        if i - k + 1 >= 0:
            s -= f[i - K + 1]
    return res


M, K = N, 1
for k in range(1, N + 1):
    m = calc(k)
    if 0 <= m < M:
        M = m
        K = k
print(M, K)
