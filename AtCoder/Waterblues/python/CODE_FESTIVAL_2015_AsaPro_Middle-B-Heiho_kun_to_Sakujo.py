INF = float('inf')
N = int(input())
S = input()


def lcs(s, t):
    dp = [[0] * (len(t) + 1) for _ in range(len(s) + 1)]
    for i in range(len(s)):
        for j in range(len(t)):
            if s[i] == t[j]:
                dp[i + 1][j + 1] = dp[i][j] + 1
            else:
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1])
    return dp[-1][-1]


res = N
for i in range(1, N):
    res = min(res, N - 2 * lcs(S[:i], S[i:]))
print(res)
