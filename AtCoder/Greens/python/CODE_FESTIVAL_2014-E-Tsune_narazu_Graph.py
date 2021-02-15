N = int(input())
R = list(map(int, input().split()))

dp = [[0, 0] for _ in range(N)]
for i in range(N):
    dp[i][0] = dp[i][1] = 1
    for j in range(i):
        if R[j] < R[i]:
            dp[i][0] = max(dp[i][0], dp[j][1] + 1)
        if R[j] > R[i]:
            dp[i][1] = max(dp[i][1], dp[j][0] + 1)
res = max(dp[N - 1][0], dp[N - 1][1])
if res < 3:
    res = 0
print(res)
