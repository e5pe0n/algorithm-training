N = int(input())
A = list(map(int, input().split()))

res = [0] * N
x = 1
for j in range(31):
    a = [0] * N
    cnt = 0
    cnt_zero = 0
    for i in range(N):
        t = A[i] >> j
        if t & 1:
            a[i] = 1
            cnt += 1
        if t == 0:
            cnt_zero += 1
    if cnt_zero == N:
        break
    for i in range(N):
        if cnt % 2 == 0:
            res[i] += a[i] * x
        else:
            res[i] += (a[i] ^ 1) * x
    x *= 2
print(' '.join([str(r) for r in res]))
