def ns(f):
    return next(f).strip()


with open("../testset/duplicate_combinations/test1.txt", 'r') as f:
    n, m, M = map(int, ns(f).split())
    a = list(map(int, ns(f).split()))

dp = [[1] + [0] * m for _ in range(n + 1)]

for i in range(n):
    for j in range(1, m + 1):
        if j - 1 - a[i] >= 0:
            dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M
        else:
            dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M
print(dp[n][m])
