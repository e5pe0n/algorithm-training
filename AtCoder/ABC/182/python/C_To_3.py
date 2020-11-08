N = input()


M = len(N)
res = M
for i in range(1, 1 << M):
    cnt = 0
    t = ""
    for j in range(M - 1, -1, -1):
        if i >> j & 1:
            cnt += 1
            t += N[j]
    if int(t) % 3 == 0:
        res = min(res, M - cnt)
if res == M:
    res = -1
print(res)
