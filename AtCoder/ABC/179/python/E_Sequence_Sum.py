N, X, M = map(int, input().split())

ordinal = [-1] * M
rec = []
cyc = []
res = 0
for i in range(N):
    if ordinal[X] != -1:
        cyc = rec[ordinal[X]:i]
        break
    ordinal[X] = i
    rec.append(X)
    res += X
    X = X * X % M
N -= len(rec)
if N == 0:
    print(res)
    exit()
freq = len(cyc)
q = N // freq
r = N % freq
_sum = [0] * (freq + 1)
for i in range(freq):
    _sum[i + 1] = _sum[i] + cyc[i]
res += _sum[freq] * q + _sum[r]
print(res)
