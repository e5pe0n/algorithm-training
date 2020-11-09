INF = float('inf')


def ns(f):
    return next(f).strip()


with open("../testset/travelling_salesman_problem/test1.txt", 'r') as f:
    n, m = map(int, ns(f).split())
    d = [[INF] * n for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, ns(f).split())
        d[u][v] = w

dp = [[-1] * n for _ in range(1 << n)]


def rec(S, v):
    global dp
    if dp[S][v] >= 0:
        return dp[S][v]
    if S == (1 << n) - 1 and v == 0:
        dp[S][v] = 0
        return dp[S][v]
    res = INF
    for u in range(n):
        if not S >> u & 1:
            res = min(res, rec(S | 1 << u, u) + d[v][u])
    dp[S][v] = res
    return dp[S][v]


print(rec(0, 0))
