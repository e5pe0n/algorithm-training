# 904 ms
from bisect import bisect


INF = float('inf')


N, D, A = map(int, input().split())
XH = [list(map(int, input().split())) for _ in range(N)]

XH.sort()
X = [xh[0] for xh in XH] + [INF]
H = [xh[1] for xh in XH]
R = [0] * N

for i in range(N):
    idx = bisect(X, X[i] + 2 * D)
    R[i] = idx - 1

sm = [0] * (N + 1)
res = 0
for i in range(N - 1, -1, -1):
    d = max(0, H[i] - sm[i + 1] + sm[R[i] + 1])
    c = (d + A - 1) // A
    res += c
    sm[i] = sm[i + 1] + c * A
print(res)
