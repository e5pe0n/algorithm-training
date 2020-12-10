S = input()
N = len(S)
K = int(input())

dp = [[[0] * (K + 1) for _ in range(2)] for _ in range(N + 1)]
dp[0][0][0] = 1
for i in range(N):
    D = int(S[i])
    for j in range(2):
        for k in range(K + 1):
            if k == K:
                dp[i + 1][j][k] += dp[i][j][k]
                continue
            for d in range(10 if j else D + 1):
                if d == 0:
                    dp[i + 1][int(j or d < D)][k] += dp[i][j][k]
                else:
                    dp[i + 1][int(j or d < D)][k + 1] += dp[i][j][k]
print(dp[N][0][K] + dp[N][1][K])
