# TLE
N = int(input())
S = list(input())
Q = int(input())
n = 1
while n < N:
    n *= 2
N = n

dat = {c: [0] * (1 << 20) for c in range(ord('a'), ord('z') + 1)}


def update(k, c, a):
    global dat
    k += N - 1
    dat[c][k] = a
    while k > 0:
        k = (k - 1) // 2
        dat[c][k] = dat[c][k * 2 + 1] + dat[c][k * 2 + 2]


def query(c, l, r, k, left, right):
    if right <= l or r <= left:
        return 0
    if l <= left and right <= r:
        return dat[c][k]
    else:
        nl = query(c, l, r, k * 2 + 1, left, (left + right) // 2)
        nr = query(c, l, r, k * 2 + 2, (left + right) // 2, right)
        return nl + nr


for i, c in enumerate(S):
    update(i, ord(c), 1)

for _ in range(Q):
    t, l, r = input().split()
    if t == "1":
        i = int(l) - 1
        update(i, ord(S[i]), 0)
        S[i] = r
        update(i, ord(r), 1)
    else:
        cnt = 0
        l, r = map(int, (l, r))
        for c in range(ord('a'), ord('z') + 1):
            v = query(c, l - 1, r, 0, 0, N)
            if v > 0:
                cnt += 1
        print(cnt)
