MOD = int(1e9) + 7
S = int(input())
dp = [1] + [0] * S
for i in range(3, S + 1):
    dp[i] = (dp[i - 3] + dp[i - 1]) % MOD
print(dp[S])
