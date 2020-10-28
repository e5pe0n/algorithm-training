def ns(f):
    return next(f).strip()


with open("../testset/partition_function/test1.txt", 'r') as f:
    n, m = map(int, ns(f).split())
    M = int(ns(f))


dp = [[0] * (n + 1) for _ in range(m + 1)]
dp[0][0] = 1
for i in range(1, m + 1):
    for j in range(n + 1):
        if j - i >= 0:
            dp[i][j] = (dp[i][j - i] + dp[i - 1][j]) % M
        else:
            dp[i][j] = dp[i - 1][j]
print(dp[m][n])
