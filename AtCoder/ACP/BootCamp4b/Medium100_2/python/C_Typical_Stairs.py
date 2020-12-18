MOD = 10**9 + 7
N, M = map(int, input().split())
A = [int(input()) for _ in range(M)]
B = [False] * (N + 1)
for a in A:
    B[a] = True
dp = [1] + [0] * N
for i in range(N):
    if i + 1 <= N and not B[i + 1]:
        dp[i + 1] = (dp[i + 1] + dp[i]) % MOD
    if i + 2 <= N and not B[i + 2]:
        dp[i + 2] = (dp[i + 2] + dp[i]) % MOD
print(dp[N])
