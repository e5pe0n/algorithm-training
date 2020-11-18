MOD = 998244353
N, K = map(int, input().split())
X = [list(map(int, input().split())) for _ in range(K)]

dp = [0] * N
sdp = [0] * (N + 1)

dp[0] = 1
sdp[1] = 1
for i in range(N):
    for L, R in X:
        left = max(0, i - R)
        right = max(0, i - L + 1)
        dp[i] = (dp[i] + sdp[right] - sdp[left] + MOD) % MOD
    sdp[i + 1] = (sdp[i] + dp[i]) % MOD
print(dp[-1])
