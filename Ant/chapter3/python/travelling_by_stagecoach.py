INF = float('inf')


def ns(f):
    return next(f).strip()


with open("../testset/travelling_by_stagecoach/test1.txt", 'r') as f:
    n, m, k, a, b = map(int, ns(f).split())
    a -= 1
    b -= 1
    t = list(map(int, ns(f).split()))
    d = [[-1] * m for _ in range(m)]
    for _ in range(k):
        u, v, w = map(int, ns(f).split())
        u -= 1
        v -= 1
        d[u][v] = w
        d[v][u] = w


dp = [[INF] * m for _ in range(1 << n)]
dp[(1 << n) - 1][a] = 0
res = INF
for S in range((1 << n) - 1, -1, -1):
    res = min(res, dp[S][b])
    for v in range(m):
        for i in range(n):
            if S >> i & 1:
                for u in range(m):
                    if d[v][u] >= 0:
                        dp[S & ~(1 << i)][u] = min(dp[S & ~(1 << i)][u], dp[S][v] + d[v][u] / t[i])
if res == INF:
    print("Impossible")
else:
    print(f"{res:.3f}")
