# 1268 ms
from bisect import bisect


N, D, A = map(int, input().split())
XH = [list(map(int, input().split())) for _ in range(N)]

XH.sort()
XH.append([float('inf'), float('inf')])
R = [0] * N
for i, (x, h) in enumerate(XH[:N]):
    idx = bisect(XH, [x + 2 * D, float('inf')])
    R[i] = idx - 1

sm = [0] * (N + 1)
res = 0
for i in range(N - 1, -1, -1):
    x, h = XH[i]
    d = max(0, h - sm[i + 1] + sm[R[i] + 1])
    c = (d + A - 1) // A
    res += c
    sm[i] = sm[i + 1] + c * A
print(res)
