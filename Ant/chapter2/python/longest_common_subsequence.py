def ns(f):
    return next(f).strip()


with open("../testset/longest_common_subsequence/test1.txt", 'r') as f:
    N = int(ns(f))
    S = ns(f)
    M = int(ns(f))
    T = ns(f)

dp = [[0] * (M + 1) for _ in range(N + 1)]
for i in range(N):
    for j in range(M):
        if S[i] == T[j]:
            dp[i + 1][j + 1] = dp[i][j] + 1
        else:
            dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1])
print(dp[N][M])
