INF = float('inf')


def ns(f):
    return next(f).strip()


with open("../testset/travelling_salesman_problem/test1.txt", 'r') as f:
    n, m = map(int, ns(f).split())
    d = [[INF] * n for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, ns(f).split())
        d[u][v] = w


dp = [[INF] * n for _ in range(1 << n)]
dp[(1 << n) - 1][0] = 0
for S in range((1 << n) - 2, -1, -1):
    for v in range(n):
        for u in range(n):
            if not (S >> u & 1):
                dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + d[v][u])
print(dp[0][0])
