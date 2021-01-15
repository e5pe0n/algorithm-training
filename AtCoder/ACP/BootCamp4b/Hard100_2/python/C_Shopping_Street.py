INF = float('inf')
N = int(input())
F = [list(map(int, input().split())) for _ in range(N)]
P = [list(map(int, input().split())) for _ in range(N)]

res = -INF
for i in range(1, 1 << 10):
    t = 0
    for k in range(N):
        c = 0
        for j in range(10):
            if (i >> j & 1) and F[k][j]:
                c += 1
        t += P[k][c]
    res = max(res, t)
print(res)
