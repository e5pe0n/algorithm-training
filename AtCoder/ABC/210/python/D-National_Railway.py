INF = float('inf')
H, W, C = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]

res = INF
for _ in range(2):
    dp = [[INF] * (W + 1) for _ in range(H + 1)]
    for i in range(1, H + 1):
        for j in range(1, W + 1):
            dp[i][j] = min(A[i - 1][j - 1], dp[i - 1][j] + C, dp[i][j - 1] + C)
    for i in range(1, H + 1):
        for j in range(1, W + 1):
            x = min(dp[i - 1][j] + C + A[i - 1][j - 1], dp[i][j - 1] + C + A[i - 1][j - 1])
            res = min(res, x)
    for i in range(H):
        A[i] = A[i][::-1]
print(res)
