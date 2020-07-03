N = int(input())
T = [int(input()) for _ in range(N)]

res = 1_000_000_000
for i in range(1 << N):
    b = format(i, '04b')[::-1]
    t0 = 0
    t1 = 0
    for j in range(N):
        if b[j] == '1':
            t0 += T[j]
        else:
            t1 += T[j]
    res = min(res, max(t0, t1))
print(res)
