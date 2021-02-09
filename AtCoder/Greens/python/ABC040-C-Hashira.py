INF = float('inf')
N = int(input())
A = list(map(int, input().split()))

dp = [INF] * N
dp[0] = 0
for i in range(1, N):
    if i - 2 >= 0:
        dp[i] = min(dp[i], dp[i - 2] + abs(A[i - 2] - A[i]))
    dp[i] = min(dp[i], dp[i - 1] + abs(A[i - 1] - A[i]))
print(dp[N - 1])
